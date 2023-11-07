#include <bits/stdc++.h>

#define GET_MAX(a, b) (a > b ? a : b)
#define GET_MIN(a ,b) (a < b ? a : b)

using namespace std;

int n = 0;
vector<string> res;

int char2Int(char *input, int num_sys) {
    int ret = 0;
    int count = 0;
    vector<char> temp;
    int add = 0;
    bool isSigned = false;

    while(input[count] != '\0') {
        temp.push_back(input[count]);
        count++;
    }

    for(int i = 0; i < temp.size(); i++) {
        if(i == 0 && temp[i] == '-' && num_sys == 10) isSigned = true;
        if(i == 0  && isSigned && num_sys == 10) continue;
        if(temp[i] >= 48 && temp[i] <= 57) {
            add = 48;
        } else {
            add = 55;
        }
        ret = ret * num_sys + static_cast<int>(temp[i]-add);
    }

    return isSigned ? ret * (-1) : ret;
}

int runCase(int b, char *s, char *d) {
    int ret = 0;

    if(b == 10) {
        int num_1 = char2Int(s, b);
        int num_2 = char2Int(d, b);
        long mul = num_1 * num_2;
        string ret_num = to_string(mul);
        res.push_back(ret_num);
    } else {
        int char_1 = char2Int(s, b);
        int char_2 = char2Int(d, b);
        long mul = char_1 * char_2;
        int temp = 0;
        char _ret_char[110];
        memset(_ret_char, '\0', sizeof(_ret_char));
        int i = 0;

        while(mul > 0) {
            temp = mul % 16;
            if(temp < 10) {
                temp += 48;
            } else {
                temp += 55;
            }
            _ret_char[i] = static_cast<char>(temp);
            mul /= 16;
            i++;
        }

        string ret_char(_ret_char);
        reverse(ret_char.begin(), ret_char.end());
        res.push_back(ret_char);
    }

    return ret;
} 

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int b = 0;
    char s[110];
    char d[110];

    for(int i = 0; i < n; i++) {
        cin >> b >> s >> d;
        runCase(b, s, d);
    }

    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}
