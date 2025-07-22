/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-07-23 19:57:33 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
const ll MAX_SQRT = 447ll;
const ll prime = 1e9+7;
// MO algorithm
struct Query {
 	int left, right, id;
 	bool operator < (const Query& other) {
 	 	if (left / MAX_SQRT != other.left / MAX_SQRT) {
 	 	 	return left < other.left;
 		}
 		return right < other.right;
 	}
};	
int n, q;
vector<int> A, B;
vector<ll> ansA, ansB;
map<int,int> compressVal;
vector<Query> queryA, queryB;
int cnt[2*N];
ll power_prime[2*N];

void cal_array(const vector<Query>& queries, const vector<int>& arr, vector<ll>& ans) {
 	memset(cnt, 0, sizeof(cnt));
 	int left = queries[0].left;
 	int right = queries[0].right;
 	ll val = 0ll;
 	for (int i = left; i <= right; i++) {
 	    cnt[arr[i]]++;
 	    if (cnt[arr[i]] == 1) {
 	     	val += power_prime[arr[i]];
 	    }	
 	}
 	ans[queries[0].id] = val;
 	for (int i = 1; i < q; i++) {
 		while (left < queries[i].left) {
 		 	cnt[arr[left]]--;
 		 	if (cnt[arr[left]] == 0) {
 		 	 	val -= power_prime[arr[left]];
 		 	}
 		 	left++;
 		}
 		while (left > queries[i].left) {
 		 	left--;
 		 	cnt[arr[left]]++;
 		 	if (cnt[arr[left]] == 1) {
 		 	 	val += power_prime[arr[left]];
 		 	}
 		}
 		while (right > queries[i].right) {
 		 	cnt[arr[right]]--;
 		 	if (cnt[arr[right]] == 0) {
 		 	 	val -= power_prime[arr[right]];
 		 	}
 			right--;
 		}
 		while (right < queries[i].right) {
			right++;
			cnt[arr[right]]++;
			if (cnt[arr[right]] == 1) {
			 	val += power_prime[arr[right]];
			}
 		}
 		ans[queries[i].id] = val;
	}	
}

void solve(void) {
    cin >> n >> q;
    A.resize(n+1);
    B.resize(n+1);
    ansA.resize(q+1);
    ansB.resize(q+1);
    power_prime[0] = 1ll;
    for (int i = 1; i <= 2*n; i++) {
     	power_prime[i] = power_prime[i-1] * prime;
    }
    for (int i = 1; i <= n; i++) {
     	cin >> A[i];
     	if (compressVal.find(A[i]) == compressVal.end()) {
     	    compressVal[A[i]] = compressVal.size() + 1;
     	}	
     	A[i] = compressVal[A[i]];
    }
    for (int i = 1; i <= n; i++) {
     	cin >> B[i];
     	if (compressVal.find(B[i]) == compressVal.end()) {
     	    compressVal[B[i]] = compressVal.size()+1;
     	}
     	B[i] = compressVal[B[i]];	
    }
    for (int i = 1; i <= q; i++) {
     	int left_a, right_a;
     	int left_b, right_b;
     	cin >> left_a >> right_a >> left_b >> right_b;
     	queryA.push_back({left_a, right_a, i});
     	queryB.push_back({left_b, right_b, i});
    }
    sort(queryA.begin(), queryA.end());
    sort(queryB.begin(), queryB.end());
   	cal_array(queryA, A, ansA);
   	cal_array(queryB, B, ansB);
   	for (int i = 1; i <= q; i++) {
   	 	if (ansA[i] == ansB[i]) {
   	 	 	cout << "YES" << endl;
   	 	} else {
   	 	 	cout << "NO" << endl;
   	 	}
   	}
}	

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG
	solve();
	return 0;
}

































