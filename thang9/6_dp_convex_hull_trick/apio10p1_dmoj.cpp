/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-10 20:08:03 
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
const ll N = 1e6+5;
int n;
ll A, B, C;
ll sum[N];
ll F[N];
vector<Node> hull;

pair<ll,ll> intersect(Node line1, Node line2) {
 	ll product = line1.b - line2.b;
 	ll factor = line2.a - line1.a;
 	if (factor < 0ll) {
 	 	factor = -factor;
 	 	product = -product;
 	}
 	return {product, factor};
}

bool isNotImportant(Node preLastLine, Node lastLine, Node new_line) {
 	pair<ll,ll> i1 = intersect(preLastLine, lastLine);
 	pair<ll,ll> i2 = intersect(preLastLine, new_line);
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
 	return hull[pos].a * x + hull[pos].b;
}

void solve(void) {
	cin >> n >> A >> B >> C;
	for (int i = 1; i <= n; i++) {
	    ll temp;
	    cin >> temp;
	    sum[i] = sum[i-1] + temp;
	}	
	F[1] = A*sum[1]*sum[1] + B*sum[1] + C;
	hull.push_back((Node){-2ll*A*sum[1], F[1] + A*sum[1]*sum[1] - B*sum[1], -1ll, 1ll});
	for (int i = 2; i <= n; i++) {
	 	ll x = sum[i];
	 	F[i] = 0ll;
	 	ll temp = query(x);
	 	if (temp > 0ll) {
	 	 	F[i] = temp;
	 	}
	 	F[i] += A*sum[i]*sum[i] + B*sum[i] + C;
	 	Node new_line = (Node){-2ll * A * sum[i], F[i] + A*sum[i]*sum[i] - B*sum[i], -1ll, 1ll};
	 	while (hull.size() >= 2 && isNotImportant(hull[(int)hull.size()-2], hull.back(), new_line) == true) {
	 	 	hull.pop_back();
	 	}
	 	pair<ll,ll> isect = intersect(hull.back(), new_line);
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

