/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-08 19:59:17 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
  	ll a, b;
  	ll product;
  	ll factor;
};
const ll N = 2e5+10;
int n;
ll C;
ll H[N];
ll F[N];
vector<Node> hull;

pair<ll,ll> intersect(Node line1, Node line2) { // calculate the intersector between line1 and line2
 	ll product = line1.b - line2.b; // b1 - b2
 	ll factor = line2.a - line1.a; // a2 - a1;
 	if (factor < 0ll) {
 	 	factor = -factor;
 	 	product = -product;
 	}
 	return {product, factor};
}

bool isNotImportant(Node preLastLine, Node lastLine, Node new_line) {
 	pair<ll,ll> i1 = intersect(preLastLine, lastLine);
 	pair<ll,ll> i2 = intersect(preLastLine, new_line);
	return i1.first * i2.second > i2.first * i1.second; // compare (b1-b2)/(a2-a1) with (b3-b4)/(a4-a3)
}

ll query(ll x) {
 	int left = 0;
 	int right = hull.size()-1;
 	int pos = -1;
 	while (left <= right) {
 	 	int mid = (left+right)>>1;
 	 	if (hull[mid].product <= x * hull[mid].factor) { // pos mid is : (b1-b2)/(a2-a1)
 	 	 	pos = mid;
 	 	 	left = mid + 1;
 	 	} else {
 	 	 	right = mid - 1;
 	 	}
 	}
 	return hull[pos].a * x + hull[pos].b;
}

void solve(void) {
	cin >> n >> C;
	for (int i = 1; i <= n; i++) cin >> H[i];
	F[1] = 0ll;
	hull.push_back((Node){-2ll*H[1], F[1] + H[1]*H[1], -1ll, 1ll});
	for (int i = 2; i <= n; i++) {
	 	ll x = H[i];
	 	F[i] = query(x);
	 	F[i] += H[i] * H[i] + C;
	 	Node new_line = (Node){-2ll*H[i], F[i] + H[i]*H[i], -1ll, 1ll};
	 	while (hull.size() >= 2 && isNotImportant(hull[hull.size()-2], hull.back(), new_line) == true) {
	 	 	hull.pop_back();
		}
		pair<ll,ll> isect = intersect(new_line, hull.back());
		new_line.product = isect.first;
		new_line.factor = isect.second;
		hull.push_back(new_line);
	}
	cout << F[n] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

