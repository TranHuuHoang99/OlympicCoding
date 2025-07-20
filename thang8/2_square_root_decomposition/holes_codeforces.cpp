#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int n, q, A[N];
// we are going to separate each element into a block and the number of each element in block is less than or equal to square of N
// and the number of blocks also are less than or equal to square of N
int lastPosInHole[N]; // this array store the position if we jump from hole i to the last hole in the same block
int steps[N]; // this array store the number of steps we can make from a element to another element in the same block
int nextPos[N]; // this array store the next hole if we jump from hole to another element in other hole
const int max_block = 375; // because square of 1e5 is 375 so we have maximum number of blocks are 375

void solve(void) {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = n; i >= 1; i--) {
	 	lastPosInHole[i] = i;
		steps[i] = 0;
		nextPos[i] = min(n+1, i + A[i]);
		if (nextPos[i] <= n && i / max_block == nextPos[i] / max_block) {
		 	lastPosInHole[i] = lastPosInHole[nextPos[i]];
		 	steps[i] = steps[nextPos[i]] + 1;
		}
	}
	for (int i = 1; i <= q; i++) {
	 	int type;
	 	cin >> type;
	 	if (type == 0) {
	 	 	int pos, val;
	 	 	cin >> pos >> val;
	 	 	A[pos] = val;
	 	 	for (int j = pos; j / max_block == pos / max_block && j >= 1; j--) {
	 	 	 	lastPosInHole[j] = j;
	 	 	 	steps[j] = 0;
	 	 	 	nextPos[j] = min(n+1, j+A[j]);
	 	 	 	if (nextPos[j] <= n && j / max_block == nextPos[j] / max_block) {
	 	 	 	 	lastPosInHole[j] = lastPosInHole[nextPos[j]];
	 	 	 	 	steps[j] = steps[nextPos[j]] + 1;
	 	 	 	}
	 	 	}
	 	} else {
	 	 	int pos;
	 	 	cin >> pos;
	 	 	int temp = pos;
	 	 	int ret_steps = 0;
	 	 	int ret_pos = 0;
	 	 	while (temp <= n) {
	 	 	 	ret_pos = temp;
	 	 	 	if (lastPosInHole[temp] != temp) {
	 	 	 	 	ret_steps += steps[temp];
	 	 	 	 	temp = lastPosInHole[temp];
	 	 	 	} else {
	 	 	 	 	ret_steps++;
	 	 	 	 	temp = nextPos[temp];
	 	 	 	}
	 	 	}
	 	 	cout << ret_pos << ' ' << ret_steps << endl;
	 	}
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























