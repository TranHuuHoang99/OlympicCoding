#include <bits/stdc++.h>

#define ll long long
using namespace std;

int N, M;
vector<int> pay;
map<int,set<int>> friend_ship;

void solve(void) {
    vector<vector<int>> relations;
    vector<bool> isVisisted(N+1, false);
    queue<int> q;

    for(int i = 1; i <= N; i++) {
        if(isVisisted[i]) continue;
        vector<int> temp_arr;
        temp_arr.push_back(i);
        q.push(i);
        isVisisted[i] = true;
        
        while(!q.empty()) {
            int temp = q.front();
            q.pop();

            for(auto f : friend_ship[temp]) {
                if(!isVisisted[f]) {
                    q.push(f);
                    isVisisted[f] = true;
                    temp_arr.push_back(f);
                }
            }
        }

        relations.push_back(temp_arr);
    }

    int count = 0;
    for(auto rl : relations) {
        int min_value = INT32_MAX;
        for(auto _rl : rl) {
            min_value = min(min_value, pay[_rl]);
        }
        count += min_value;
    }
    
    cout << count << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif //HOANG_DEBUG

    cin >> N >> M;
    pay.assign(N+1, 0);

    for(int i = 1; i <= N; i++) {
        cin >> pay[i];
        friend_ship[i];
    }

    int A, B;
    for(int i = 0; i < M; i++) {
        cin >> A >> B;
        friend_ship[A].insert(B);
        friend_ship[B].insert(A);
    }

    solve();

    return 0;
}
