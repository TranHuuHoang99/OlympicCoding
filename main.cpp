#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> res;
string A;
int N;
vector<string> adp = {
    "and", "in", "on", "at", "to", "of", "from", "for", "with"
};

bool cmp(string A, string B) {
    return strcmp(A.c_str(), B.c_str()) == 0;
}

void solve(vector<vector<string>> W) {
    queue<string> q;
    vector<string> dp;
    for(string _w : W[0]) {
        if(cmp(_w, A.substr(0, _w.size()))) {
            q.push(_w);
        }
    }

    for(int i = 1; i < N; i++) {
        dp.clear();
        while(!q.empty()) {
            string temp = q.front();
            q.pop();

            for(string w : W[i]) {
                string next = temp + w;
                if(!dp.empty() && cmp(dp.back(), next)) continue;
                if(cmp(next, A.substr(0,next.size()))) {
                    dp.push_back(next);
                }
            }
        }
        for(string _dp : dp) q.push(_dp);
    }

    int count = 0;
    for(string _dp : dp) {
        if(cmp(_dp, A)) count++; 
    }

    res.push_back(count);
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
    while(T--) {
        cin >> N;
        cin >> A;
        vector<vector<string>> W(N);
        string temp;
        for(int i = 0; i < N; i++) {
            cin >> temp;
            int add = 0;
            for(auto _adp : adp) {
                if(strcmp(temp.c_str(), _adp.c_str()) == 0) {
                    add = 1;
                    break;
                }
            }

            W[i].assign(temp.size()+add, "");
            for(int j = add; j < temp.size()+add; j++) {
                W[i][j] = temp.substr(0,j+1-add);
            }
        }

        solve(W);
    }

    for(auto r : res) {
        cout << r << endl;
    }

    return 0;
}
