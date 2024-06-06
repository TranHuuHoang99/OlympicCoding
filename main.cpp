#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N;
vector<int> A;
int ret = 0;

bool bin_search(int find, int l, int r) {
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(2*A[mid] == find) {
            return true;
        } else if(2*A[mid] < find) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    return false;
}

void solve(void) {
    for(int i = N; i >= 2; i--) {
        for(int j = 1; j <= N-i+1; j++) {
            int temp = A[j+i-1]+A[j-1];
            if(bin_search(temp, j, j+i-1)) {
                ret = max(ret, i);
                return;
            }
        }
    }
}
  
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG

    cin >> N;
    A.resize(N+1);

    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] += A[i-1];
    }

    solve();
    cout << ret << endl;

    return 0;
}
