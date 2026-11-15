/*
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-11-15 16:20:31
**************************************************************************
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define pi acos(-1.0)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int cnt[3][30];
vector<string> str(3);
void solve(void) {
    for (int i = 0; i < 3; i++) {
        cin >> str[i];
        for (char c : str[i]) {
            int idx = c - 'A';
            cnt[i][idx] += 1;
        }
    }
    vector<string> ret;
    while (true) {
        int rem[3] = {0,0,0};
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            for (int c = 0; c < 26; c++) {
                rem[i] += cnt[i][c];
            }
            sum += rem[i];
        }
        if (sum == 0) break;
        int c_head = -1;
        int c_tail = -1;
        int most_used = 0;
        int best_numb = 0;
        for (int c = 0; c < 26; c++) {
            int cnt_need = 0;
            int cnt_numb = 0;
            for (int i = 0; i < 3; i++) {
                if (cnt[i][c] > 0) {
                    cnt_need += 1;
                    cnt_numb += cnt[i][c];
                }
            }
            if (cnt_need == 0) continue;
            if (cnt_need > most_used || (cnt_need == most_used && cnt_numb % 2 == 1 && best_numb % 2 == 0)) {
                most_used = cnt_need;
                best_numb = cnt_numb;
                c_head = c;
            }
        }
        if (most_used == 3 && best_numb % 2 == 1) {
            for (int i = 0; i < 3; i++) {
                cnt[i][c_head] -= 1;
            }
            c_tail = c_head;
        } else if (most_used >= 2) {
            vector<int> order = {0, 1, 2};
            sort(order.begin(), order.end(), [=](int a, int b) -> bool {
                return cnt[a][c_head] > cnt[b][c_head];
            });
            bool used_as_head[3] = {false, false, false};
            for (int j = 0; j < 2; j++) {
                int i = order[j];
                if (cnt[i][c_head] > 0) {
                    cnt[i][c_head] -= 1;
                    used_as_head[i] = true;
                }
            }
            c_tail = c_head;
            int least_used = 4;
            for (int i = 0; i < 3; i++) {
                if (used_as_head[i]) continue;
                for (int c = 0; c < 26; c++) {
                    if (cnt[i][c] > 0) {
                        int cnt_need = 0;
                        for (int j = 0; j < 3; j++) {
                            if (cnt[j][c] > 0) cnt_need += 1;
                        }
                        if (cnt_need < least_used) {
                            least_used = cnt_need;
                            c_tail = c;
                        }
                    }
                }
                if (least_used < 4) {
                    cnt[i][c_tail] -= 1;
                }
            }
        } else {
            vector<int> order = {0, 1, 2};
            sort(order.begin(), order.end(), [=](int a, int b) -> bool {
                return rem[a] > rem[b];
            });
            for (int c = 0; c < 26; c++) {
                int i = order[0];
                if (cnt[i][c] > 0) {
                    c_head = c;
                    cnt[i][c] -= 1;
                    break;
                }
            }
            c_tail = c_head;
            if (rem[order[1]] > 0) {
                for (int c = 0; c < 26; c++) {
                    int i = order[1];
                    if (cnt[i][c] > 0) {
                        c_tail = c;
                        cnt[i][c] -= 1;
                        break;
                    }
                }
            }
        }
        string str = "";
        str += char(c_head + 'A');
        str += char(c_tail + 'A');
        ret.push_back(str);
    }
    cout << ret.size() << '\n';
    for (string r : ret) cout << r << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
