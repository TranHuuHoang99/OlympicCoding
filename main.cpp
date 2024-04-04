#include <bits/stdc++.h>

using namespace std;

int n = 0, m = 0;
vector<bool> isVisited;
map<int,set<int>> cows;
set<int> ret;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    isVisited.assign(n+1, false);
    int cow1 = 0;
    int cow2 = 0;
    set<int> temp_s;
    for(int i = 1; i <= n; i++) {
        cows[i] = temp_s;
    }

    for(int i = 0; i < m; i++) {
        cin >> cow1 >> cow2;
        cows[cow1].insert(cow2);
        cows[cow2].insert(cow1);
    }

    queue<int> q;
    int temp = 0;
    isVisited[1] = true;

    for(auto s : cows[1]) {
        q.push(s);
    }
    
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        isVisited[temp] = true;

        for(auto s : cows[temp]) {
            if(!isVisited[s]) {
                isVisited[s] = true;
                q.push(s);
            }
        }
    }

    bool isValid = true;
    for(int i = 1; i <= n; i++) {
        if(!isVisited[i]) {
            cout << i << " ";
            isValid = false;
        }
    }
    
    if(isValid) {
        cout << 0 << endl;
    } else {
        cout << "\n";
    }

    return 0;
}
