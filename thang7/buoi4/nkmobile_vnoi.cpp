#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1024+10;
const int len = 1024;
int n;
int fw[N][N];

void update_fw2d(int x, int y, int val) {
 	for (int i = x; i <= len; i+=i&-i) {
 	 	for (int j = y; j <= len; j+=j&-j) {
 	 	 	fw[i][j] += val;
 		}
 	}
}

int get_fw2d(int x, int y) {
 	int ret = 0;
 	for (int i = x; i >= 1; i-=i&-i) {
 	 	for (int j = y; j >= 1; j-=j&-j) {
 	 	 	ret += fw[i][j];
 	 	}
 	}
	return ret;
}

void solve(void) {
	int q;
	cin >> q >> n;
	n++;
	while (1) {
		cin >> q;
		if (q == 3) return;
		if (q == 1) {
		 	int x, y, a;
		 	cin >> x >> y >> a;
		 	x++;
		 	y++;
		 	update_fw2d(x, y, a);
		} else {
		 	int x1, y1, x2, y2;
		 	cin >> x1 >> y1 >> x2 >> y2;
		 	x1++;
		 	y1++;
		 	x2++;
		 	y2++;
		 	int ret = get_fw2d(x2, y2) - get_fw2d(x1-1,y2) - get_fw2d(x2, y1-1) + get_fw2d(x1-1, y1-1);
		 	cout << ret << endl; 
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
#endif // HOANGPRODN_DEBUG
	solve();

	return 0;
}

