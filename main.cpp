#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
    int N, H;
    cin >> N >> H;
    vector<vector<int>> woods(2);
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        woods[i%2].push_back(temp);
    }

    sort(woods[0].begin(), woods[0].end());
    sort(woods[1].begin(), woods[1].end());

    map<int,int> ret;

    for (int i = 1; i <= H; i++) {
        auto it_up = lower_bound(woods[0].begin(), woods[0].end(), i);
        auto it_down = upper_bound(woods[1].begin(), woods[1].end(), H-i);
        int len = N/2-(it_up - woods[0].begin()) + N/2-(it_down - woods[1].begin());
        ret[len]++;
    }

    cout << ret.begin()->first << " " << ret.begin()->second << endl;
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
