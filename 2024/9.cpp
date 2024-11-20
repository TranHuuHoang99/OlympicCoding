#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 10;
pair<int,int> A;
pair<int,int> B;
pair<int,int> P[N];
int n;

void solve(void) {
	cin >> n;
	cin >> A.first >> A.second;
	cin >> B.first >> B.second;
	for (int i = 0; i < n; i++) {
		cin >> P[i].first >> P[i].second;
	}
	int len = 1 << n;
	int ret = INT32_MAX;
	for (int n_mask = 0; n_mask < len; n_mask++) {
		vector<pair<int,int>> arr1;
		vector<pair<int,int>> arr2;
		arr1.push_back(A);
		arr2.push_back(B);
		for (int i = 0; i < n; i++) {
			if (n_mask & (1 << i)) {
				arr1.push_back(P[i]);
			} else {
				arr2.push_back(P[i]);
			}
		}
		int sum1 = INT32_MAX;
		do {
			vector<pair<int,int>> temp = arr1;
			temp.push_back(A);
			int sum_temp = 0;
			for (int i = 1; i < temp.size(); i++) {
				int val = abs(temp[i].first - temp[i-1].first);
				val += abs(temp[i].second - temp[i-1].second);
				val *= i;
				sum_temp += val;
			}
			sum1 = min(sum1, sum_temp);
		} while (next_permutation(arr1.begin()+1, arr1.end()));
		int sum2 = INT32_MAX;
		do {
			vector<pair<int,int>> temp = arr2;
			temp.push_back(B);
			int sum_temp = 0;
			for (int i = 1; i < temp.size(); i++) {
				int val = abs(temp[i].first - temp[i-1].first);
				val += abs(temp[i].second - temp[i-1].second);
				val *= i;
				sum_temp += val;
			}
			sum2 = min(sum2, sum_temp);
		} while (next_permutation(arr2.begin()+1, arr2.end()));
		ret = min(ret,sum1+sum2);
	}
	cout << ret << endl;
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();

    return 0;
}




