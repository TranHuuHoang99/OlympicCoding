/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-09 20:20:49 
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
struct Rect {
  	ll width, height;
};
const ll N = 5e4+10;
int n;
Rect A[N];
vector<Rect> save;
vector<Node> hull;
ll F[N];

bool cmp(Rect a, Rect b) {
 	if (a.width == b.width) return a.height > b.height;
 	return a.width > b.width;
}

pair<ll,ll> intersect(Node line1, Node line2) {
 	ll product = line2.b - line1.b;
 	ll factor = line1.a - line2.a;
 	if (factor < 0ll) {
 	 	factor = -factor;
 	 	product = -product;
 	}
 	return {product, factor};
}

bool isNotImportant(Node preLast, Node last, Node new_line) {
 	pair<ll,ll> i1 = intersect(preLast, last);
 	pair<ll,ll> i2 = intersect(preLast, new_line);
 	return i1.first * i2.second > i2.first * i1.second;
}

ll query(ll x) {
 	int left = 0;
 	int right = hull.size()-1;
 	int pos = -1;
 	while (left <= right) {
 	    int mid = (left+right)>>1;
 	    if (hull[mid].product <= x * hull[mid].factor) {
 	     	pos = mid;
 	     	left = mid + 1;
 	    } else {
 	     	right = mid - 1;
 	    }
 	}
 	return hull[pos].a *x + hull[pos].b;	
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i].width >> A[i].height;
	}
	sort(A+1,A+1+n, cmp);
	save.push_back(A[1]);
	for (int i = 2; i <= n; i++) {
	 	if (A[i].height <= save.back().height) continue;
	 	save.push_back(A[i]);
	}
	n = save.size();
	F[0] = 0ll;
	hull.push_back((Node){save[0].width, F[0], -1ll, 1ll});
	F[1] = save[0].width * save[0].height;
	for (int i = 2; i <= n; i++) {
		Node new_line = (Node){save[i-1].width, F[i-1], -1ll, 1ll};
	 	while (hull.size() >= 2 && isNotImportant(hull[hull.size()-2], hull.back(), new_line) == true) {
	 	 	hull.pop_back();
	 	}
	 	pair<ll,ll> isec = intersect(hull.back(), new_line);
	 	new_line.product = isec.first;
	 	new_line.factor = isec.second;
	 	hull.push_back(new_line);
	 	F[i] = query(save[i-1].height);
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

