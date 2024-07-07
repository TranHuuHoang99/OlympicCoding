#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> res;

void solve(void) {
    int N, A, B;
    cin >> N;
    vector<pair<int,int>> woods(N);
    for (int i = 0; i < N; i++) {
        cin >> woods[i].first >> woods[i].second;
    }

    sort(woods.begin(), woods.end());

    multiset<int> temp;
    temp.insert(woods[N-1].second);
    for (int i = N-2; i >= 0; i--) {
        auto it = temp.lower_bound(woods[i].second);
        if (it != temp.end()) {
            temp.erase(it);
        }
        temp.insert(woods[i].second);
    }

    res.push_back(temp.size());
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    for (auto r : res) {
        cout << r << endl;
    }

    return 0;
}
