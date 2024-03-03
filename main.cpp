#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<vector<int>> ret_int;

        void dfs(int ver, int hor, const int &len, map<int,int> get_ret, vector<int> temp_ret) {
            if(ver >= len-1) {
                ret_int.push_back(temp_ret);
                return;
            }

            for(int i = 0; i < len; i++) {
                if(i-1 == hor || i+1 == hor || get_ret.find(i) != get_ret.end()) {
                    continue;
                }

                get_ret[i] = i;
                temp_ret.push_back(i);
                dfs(ver+1, i, len, get_ret, temp_ret);
                get_ret.erase(i);
                temp_ret.pop_back();
            }

            return;
        }

        vector<vector<string>> solveNQueens(int n) {    
            string temp;
            for(int i = 0; i < n; i++) temp += '.';
            vector<vector<string>> ret;
            map<int,int> get_ret;
            vector<int> temp_ret;
            
            for(int i = 0; i < n; i++) {
                get_ret[i] = i;
                temp_ret.push_back(i);
                dfs(0, i, n, get_ret, temp_ret);
                get_ret.clear();
                temp_ret.clear();
            }

            ret.assign(ret_int.size(), vector<string>(n, temp));

            for(int i = 0; i < ret_int.size(); i++) {
                for(int j = 0; j < ret_int[i].size(); j++) {
                    ret[i][j][ret_int[i][j]] = 'Q';
                }
            }

            return ret;
        }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution solve;
    
    for(auto c : solve.solveNQueens(4)) {
        for(auto sub_c : c) {
            cout << sub_c << ", ";
        }
        cout << "\n";
    }

    return 0;
}
