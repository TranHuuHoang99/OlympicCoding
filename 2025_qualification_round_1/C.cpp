/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-19 09:12:53 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
  	ll a, b, c, d;
  	Node(ll _a = 0, ll _b = 0, ll _c = 0, ll _d = 0) : a(_a), b(_b), c(_c), d(_d) {}
	Node operator+(const Node& other) {
	 	return Node(a+other.a, b+other.b, c+other.c, d+other.d);
	}
	Node operator-(const Node& other) {
	 	return Node(a-other.a, b-other.b, c-other.c, d-other.d);
	}
};
Node F0[32], F1[32], F2[32], F3[32];
void init(void) {
	F0[0] = Node(0,0,0,0);
	F1[0] = Node(0,0,0,0);
	F2[0] = Node(0,0,0,0);
	F3[0] = Node(0,0,0,0);
	for (int k = 1; k <= 30; k++) {
	 	F0[k] = Node(1,0,0,0) + F0[k-1] + F0[k-1] + F1[k-1] + F2[k-1];
	 	F1[k] = Node(0,1,0,0) + F1[k-1] + F1[k-1] + F0[k-1] + F3[k-1];
	 	F2[k] = Node(0,0,1,0) + F2[k-1] + F2[k-1] + F0[k-1] + F3[k-1];
	 	F3[k] = Node(0,0,0,1) + F3[k-1] + F3[k-1] + F1[k-1] + F2[k-1];
	}
}
void solve(void) {
	int k;
	ll a, b, c, d;
	cin >> k >> a >> b >> c >> d;
	ll x = 0, y = 0;
	Node cur(a, b, c, d);
	bool isValid = true;
	for ( ; k >= 1; k--) {
	 	ll half = 1ll << (k-1);
	 	ll max_val = max(max(cur.a, cur.b), max(cur.c, cur.d));
	 	ll min_val = min(min(cur.a, cur.b), min(cur.c, cur.d));
	 	int quater = -1;
	 	if (cur.a == min_val && cur.d == max_val) {
	 	 	quater = 0;
	 	} else if (cur.a == max_val && cur.d == min_val) {
	 	 	quater = 3;
	 	} else if (cur.b == min_val && cur.c == max_val) {
	 	 	quater = 1;
	 	} else if (cur.b == max_val && cur.c == min_val) {
	 	 	quater = 2;
	 	} else {
	 		isValid = false;
	 		break;
	 	}
		if (quater == 0) {
		 	cur = cur - Node(0,0,0,1) - F1[k-1] - F2[k-1] - F3[k-1];
		} else if (quater == 1) {
		 	cur = cur - Node(0,0,1,0) - F0[k-1] - F2[k-1] - F3[k-1];
		 	y += half;
		} else if (quater == 2) {
		 	cur = cur - Node(0,1,0,0) - F0[k-1] - F1[k-1] - F3[k-1];
		 	x += half;
		} else {
		 	cur = cur - Node(1,0,0,0) - F0[k-1] - F1[k-1] - F2[k-1];
		 	x += half;
		 	y += half;
		}
		if (cur.a < 0 || cur.b < 0 || cur.c < 0 || cur.d < 0) {
			isValid = false;
			break;
		}
	}
	if (!isValid || cur.a != 0 || cur.b != 0 || cur.c != 0 || cur.d != 0) {
	 	cout << -1 << ' ' << -1 << "\n";
	} else {
	 	cout << x << ' ' << y << "\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}
	return 0;
}



























