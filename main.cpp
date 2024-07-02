#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
    int N;
    ll K, L;
    cin >> N >> K >> L;
    vector<int> papers(N, 0);
    for (int i = 0; i < N; i++) cin >> papers[i];
    sort(papers.begin(), papers.end(), greater<int>());

    auto check = [=](const int &mid) -> bool {
        ll sum = 0;
        for (int i = 0; i < mid; i++) {
            if (papers[i] < mid) {
                if (mid - papers[i] > K) return false;
                sum += (mid-papers[i]);
            }
        }

        return sum <= L * K;
    };  

    int left = 0, right = N+1;
    while (left < right) {
        int mid = left + (right-left+1)/2;

        if (check(mid)) {
            left = mid;
        } else {
            right = mid-1;
        }
    }

    cout << left << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG

    solve();

    return 0;
}
