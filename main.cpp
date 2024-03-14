#include <bits/stdc++.h>

using namespace std;

int n = 0;
vector<int> A;
vector<int> B;

int solve(void) {
    int ret = INT_MIN;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            vector<int> temp_a(A.begin(), A.end());
            vector<int> temp_b(B.begin(), B.end());
            temp_a.erase(temp_a.begin()+i);
            temp_b.erase(temp_b.begin()+j);
            int count = 0;
            for(int k = 0; k < n-1; k++) {
                if(temp_a[k] == temp_b[k]) {
                    count++;
                } else {
                    count = 0;
                }
                ret = max(ret, count);
            }
        }
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    A.assign(n, 0);
    B.assign(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> B[i];
    }

    cout << solve() << endl;


    return 0;
}
