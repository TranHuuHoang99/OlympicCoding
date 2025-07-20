#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAX_SQRT = 173; // this is maximum value of sqrt if 3e4
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
const ll N = 3e4+10;
const ll Q = 2e5+10;
const ll MAX_VAL = 1e6+10;
int n, q;
int A[N];
int ans[Q];
int cnt[MAX_VAL];
vector<Query> listQueries;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	cin >> q;
	for (int i = 1; i <= q; i++) {
	 	int left, right;
	 	cin >> left >> right;
	 	listQueries.push_back((Query){left, right, i});
	}
	sort(listQueries.begin(), listQueries.end());
	int numbDiff = 0;
	int left = listQueries[0].left;
	int right = listQueries[0].right;
	for (int i = left; i <= right; i++) {
	    cnt[A[i]]++;
	    if (cnt[A[i]] == 1) {
	     	numbDiff++;
	    }
	}
	ans[listQueries[0].id] = numbDiff;
	for (int query = 1; query < q; query++) {
		while (left > listQueries[query].left) {
		    left--;
		    cnt[A[left]]++;
		    if (cnt[A[left]] == 1) {
		     	numbDiff++;
		    }
		}	
		while (left < listQueries[query].left) {
		 	cnt[A[left]]--;
		 	if (cnt[A[left]] == 0) {
		 	 	numbDiff--;
		 	}
		 	left++;
		}
		while (right < listQueries[query].right) {
		    right++;
		    cnt[A[right]]++;
		    if (cnt[A[right]] == 1) {
		     	numbDiff++;
		    }
		}
		while (right > listQueries[query].right) {
		 	cnt[A[right]]--;
		 	if (cnt[A[right]] == 0) {
		 	 	numbDiff--;
		 	}
		 	right--;
		}
		ans[listQueries[query].id] = numbDiff;
	}
	for (int i = 1; i <= q; i++) {
	 	cout << ans[i] << endl;
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




























