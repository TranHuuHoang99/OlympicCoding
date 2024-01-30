#include <bits/stdc++.h>
#include <memory>

using namespace std;

int n = 0, m = 0;

typedef long long ll;

int solve(vector<int> sys_num, vector<string> s, vector<string> d) {    
    vector<char> ret_arr;
    string ret_str;
    int temp_sys = 0;
    int count1 = 0, count2 = 0;
    ll ret1 = 0, ret2 = 0, ret = 0;
    int _sign1 = 1, _sign2 = 1;

    for(int i = 0; i < n; i++) {
        temp_sys = sys_num[i];
        ret1 = 0;
        ret2 = 0;
        ret = 0;
        ret_arr.clear();
        count1 = 0;
        count2 = 0;
        _sign1 = 1; 
        _sign2 = 1; 

        for(int j = s[i].size()-1; j >= 0; j--) {  
            if(s[i][count1] == '-') {
                _sign1 = -1;
            } else {
                if(s[i][count1] >= 65) {
                    ret1 += (static_cast<int>(s[i][count1] - 55) * pow(temp_sys, j));
                } else {
                    ret1 += (static_cast<int>(s[i][count1] - 48) * pow(temp_sys, j));
                }
            }
            count1++;
        }

        for(int j = d[i].size()-1; j >= 0; j--) {   
            if(d[i][count2] == '-') {
                _sign2 = -1;
            } else {
                if(d[i][count2] >= 65) {
                    ret2 += (static_cast<int>(d[i][count2] - 55) * pow(temp_sys, j));
                } else {
                    ret2 += (static_cast<int>(d[i][count2] - 48) * pow(temp_sys, j));
                }
            }
            count2++;            
        }

        ret = ret1 * ret2;
        int temp_int = 0;
        while(ret > 0) {
            temp_int = ret % temp_sys;
            temp_int = temp_int >= 10 ? temp_int + 55 : temp_int + 48;
            ret_arr.push_back(static_cast<char>(temp_int));
            if(ret_arr.back() == '0') ret_arr.pop_back();
            ret /= temp_sys;
        }

        if((_sign1 * _sign2) == -1) {
            ret_arr.push_back('-');
        }

        if(ret_arr.size() > 0) {
            if(ret_arr.size() == 1 && ret_arr[0] == '-') {
                ret_str = "0";
            } else {
                ret_str = string(ret_arr.rbegin(), ret_arr.rend());
            }
        } else {
            ret_str = "0";
        }
       
        cout << ret_str << endl;
    }

    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;

    vector<int> sys_num(n, 0);
    vector<string> s(n, " ");
    vector<string> d(n, " ");

    for(int i = 0; i < n; i++) {
        cin >> sys_num[i] >> s[i] >> d[i];
    }

    solve(sys_num, s, d);

    return 0;
}
