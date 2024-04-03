#include <bits/stdc++.h>

using namespace std;

int n = 0, m = 0;
map<int,set<int>> connect;
vector<bool> visits;

int solve(void) {
    int ret = 0;
    set<int> connected;
    for(int i = 1; i <= n; i++) {
        connect[i] = connected;
    }

    int index = 0;
    int value = 0;
    for(int i = 0; i < m; i++) {
        cin >> index >> value;
        connect[index].insert(value);
        connect[value].insert(index);
    }

    queue<set<int>> q;
    set<int> temp;

    for(auto c : connect) {
        if(!visits[c.first]) {
            q.push(c.second);
            ret++;
            visits[c.first] = true;
        }

        while(!q.empty()) {
            temp = q.front();
            q.pop();

            for(auto t : temp) {
                if(!visits[t]) {
                    q.push(connect[t]);
                    visits[t] = true;
                }
            }
        }
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    visits.assign(n+1, false);
    
    cout << solve() << endl;

    return 0;
}
