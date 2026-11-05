/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-05 17:50:30
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct procedures {
    string func_name;
    vector<string> params;
};
int n, m, k;
vector<string> parse_function(string str) {
    vector<string> ret;
    string get_value = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == ')' || str[i] == ',') {
            get_value += ' ';
        } else {
            get_value += str[i];
        }
    }
    stringstream ss(get_value);
    string str_save;
    while (ss >> str_save) {
        ret.push_back(str_save);
    }
    return ret;
}
void solve(void) {
    cin >> n;
    vector<procedures> save_procedures(n);
    string str;
    getline(cin, str);
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        vector<string> save_tmp = parse_function(str);
        save_procedures[i].func_name = save_tmp[1];
        for (int j = 2; j < save_tmp.size(); j++) {
            save_procedures[i].params.push_back(save_tmp[j]);
        }
    }
    cin >> m;
    map<string,string> var_to_type;
    for (int i = 1; i <= m; i++) {
        string type, var_name;
        cin >> type >> var_name;
        var_to_type[var_name] = type;
    }
    cin >> k;
    getline(cin, str);
    for (int i = 1; i <= k; i++) {
        getline(cin, str);
        vector<string> call_func = parse_function(str);
        string func_name = call_func[0];
        vector<string> params;
        for (int j = 1; j < call_func.size(); j++) {
            params.push_back(var_to_type[call_func[j]]);
        }
        int cnt = 0;
        for (procedures s : save_procedures) {
            if (func_name != s.func_name) continue;
            if (s.params.size() != params.size()) continue;
            bool valid = true;
            for (int j = 0; j < s.params.size(); j++) {
                if (s.params[j] != "T" && s.params[j] != params[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) cnt++;
        }
        cout << cnt << '\n';
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}






