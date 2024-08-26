#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ret;
        if (turnedOn == 0) {
            string str = "0:00";
            ret.push_back(str);
            return ret;
        }
        const int len = 1 << 10;
        for (int mask = 1; mask < len; mask++) {
            int cnt = 0;
            for (int i = 0; i < 10; i++) {
                if (mask & (1 << i)) cnt++;
            }

            if (cnt == turnedOn) {
                int hour = 0;
                for (int i = 0; i <= 3; i++) {
                    if (mask & (1 << i)) {
                        hour += (1 << i);
                    }
                }   

                int minute = 0;
                for (int i = 4; i <= 9; i++) {
                    if (mask & (1 << i)) {
                        minute += (1 << (i-4));
                    }
                }

                if (hour <= 11 && minute <= 59) {
                    string str;
                    str += to_string(hour);
                    str += ':';
                    if (minute < 10) {
                        str += '0';
                        str += to_string(minute);
                    } else {
                        str += to_string(minute);
                    }   

                    ret.push_back(str);
                }
            }
        }

        return ret;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG

    return 0;
}
