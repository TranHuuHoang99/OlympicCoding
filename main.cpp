#include <bits/stdc++.h>

#define ll long long
using namespace std;

const ll N = 1e5+1;
int n, m;
int c[N];
vector<int> arr;

bool isValid(int target) {
    int left = arr[0];
    int count = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i]-left >= target) {
            count++;
            left = arr[i];
        }
    }

    return count >= n-1;
}

void solve(void) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> c[i];
        arr.push_back(c[i]);
        arr.push_back(c[i]-1);
        arr.push_back(c[i]+1);
    }

    arr.resize(distance(arr.begin(), unique(arr.begin(), arr.end())));
    sort(arr.begin(), arr.end());

    int left = 0;
    int right = arr.back();

    while (left < right-1) {
        int mid = (right + left) / 2;
        if (isValid(mid)) {
            left = mid;
        } else {
            right = mid;
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
#endif //HOANG_DEBUG

    solve();

    return 0;
}
