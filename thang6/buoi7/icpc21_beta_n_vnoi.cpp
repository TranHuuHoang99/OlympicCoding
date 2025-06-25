#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll lim = 1e9;

ll ask(ll x1, ll y1, ll x2, ll y2) {
 	cout << '?' << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
 	fflush(stdout);
 	ll area;
 	cin >> area;
 	if (area == -1) {
 	 	exit(0);
 	}
 	return area;
}

void solve(void) {
	ll total_area = ask(1, 1, lim, lim);
	ll x1 = -1;
	ll left = 1;
	ll right = lim;
	while (left <= right) {
	 	ll mid = (left+right)/2;
	 	ll area = ask(1, 1, mid, lim);
	 	if (area == 0) {
	 	    left = mid + 1;
	 	} else {
	 	 	right = mid - 1;
	 	 	x1 = mid;
		}
	}
	ll single_area = ask(x1, 1, x1, lim);
	ll x = total_area / single_area;
	ll x2 = x1 + x - 1;                                                      
	left = 1;
	right = lim;
	ll y1 = -1;
	while (left <= right) {
	    ll mid = (left+right)/2;
	    ll area = ask(1, 1, lim, mid);
	    if (area == 0) {
	     	left = mid + 1;
	    } else {
	     	right = mid - 1;
	     	y1 = mid;
	    }
	}	
	ll y = total_area / x;
	ll y2 = y + y1 - 1;
	cout << '!' << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	fflush(stdout);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}

