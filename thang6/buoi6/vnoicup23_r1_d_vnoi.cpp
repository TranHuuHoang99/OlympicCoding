#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int n, k;
ll sum[N], A[N];
int cnta[26], cntb[26];
string s, t;
vector<pair<int,int>> vp, changes, matched;

ll calSum(int left, int right) {
 	return sum[right] - sum[left] + A[left];
} 

bool cmp(pair<int,int> a, pair<int,int> b) {
    return calSum(a.first,a.second) < calSum(b.first,b.second);
}	

void solve(void) {
 	cin >> n >> k;
 	cin >> s >> t;
 	for (int i = 0; i < n; i++) cin >> A[i];
 	for (int i = 0; i < n; i++) {
 	 	if (i == 0) {
 	 	 	sum[i] = A[i];
 	 	} else {
 	 	 	sum[i] = sum[i-1] + A[i];
 	 	}
 	}
 	int start = 0;
 	for (int i = 0; i < n; i++) {
 	 	cnta[s[i]-'a']++;
 	 	cntb[t[i]-'a']++;
 	 	bool isMatch = true;
 	 	for (int j = 0; j < 26; j++) {
 	 	 	if (cnta[j] != cntb[j]) {
 	 	 	 	isMatch = false;
 	 	 	 	break;
 	 	 	}
 	 	}
 	 	if (isMatch == true) {
			if (i > start) {
				vp.push_back({start,i});
			}
			start = i+1;
			for (int j = 0; j < 26; j++) {
			    cnta[j] = 0;
			    cntb[j] = 0;
			}	
 	 	}
	}
	if (vp.empty()) {
	 	cout << 0 << endl;
	 	return;
	}
	int curLeft = vp[0].first;
	int curRight = vp[0].second;
	changes.push_back({curLeft, curRight});
	for (int i = 1; i < vp.size(); i++) {
	 	if (vp[i].first == curRight+1) {
	 	 	curRight = vp[i].second;
	 	 	changes.back().second = curRight;
	 	} else {
	 	 	curLeft = vp[i].first;
	 	 	curRight = vp[i].second;
	 	 	changes.push_back({curLeft, curRight});
	 	}
	}
	for (int i = 0; i < changes.size()-1; i++) {
	 	if (changes[i].second + 1 <= changes[i+1].first-1) {
	 	 	matched.push_back({changes[i].second+1, changes[i+1].first-1});
	 	}
	}
	sort(matched.begin(), matched.end(), cmp);
	ll ret = 0ll;
	for (int i = 0; i < changes.size(); i++) {
	 	ret += calSum(changes[i].first, changes[i].second);
	}
	if (changes.size() > k) {
	 	for (int i = 0; i < changes.size()-k; i++) {
	 	 	ret += calSum(matched[i].first, matched[i].second);
	 	}
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}

































