#include <bits/stdc++.h>

using namespace std;

int n = 0;
vector<pair<int,int>> calendar;

bool isValid(pair<int,int> a, pair<int,int> b) {
    return a.first >= b.second || a.second <= b.first;
}

int solve(void) {
    int ret = 1;
    sort(calendar.begin(), calendar.end());

    for(int i = 0; i < calendar.size(); i++) {
        int count = 1;
        pair<int,int> temp = calendar[i];
        for(int j = i-1; j >= 0; j--) {
            if(isValid(temp, calendar[j])) {
                temp.first = calendar[j].first;
                count++;
            }
        }

        for(int j = 0; j < calendar.size(); j++) {
            if(isValid(temp, calendar[j])) {
                temp.second = calendar[j].second;
                count++;
            }
        }

        ret = max(ret, count);
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    calendar.assign(n, {0,0});
    for(int i = 0; i < n; i++) {
        cin >> calendar[i].first >> calendar[i].second;
    }

    cout << solve() << endl;

    return 0;
}
