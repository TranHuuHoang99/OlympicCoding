#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node {
	int a, b, val;
	bool operator < (const Node& other) const {
		return val > other.val;
	}
};

const ll N = 5e4+1;
int A[N];
int B[N];
int m, n, k;

void solve(void) {
	cin >> m >> n >> k;
	for (int i = 0; i < m; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];
	sort(A,A+m);
	sort(B,B+n);
	priority_queue<Node> q;
	for (int i = 0; i < n; i++) {
		q.push({0,i,A[0]+B[i]});
	}
	for (int i = 0; i < k; i++) {
		Node temp = q.top();
		q.pop();
		cout << temp.val << endl;
		if (temp.a < m) {
			q.push({temp.a + 1, temp.b, A[temp.a+1]+B[temp.b]});
		}
	}
}
  
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();	
	
    return 0;
}



