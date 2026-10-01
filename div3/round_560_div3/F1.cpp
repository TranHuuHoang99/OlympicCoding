/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-02 13:57:10
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct offer {
    int day, type;
};
const int len = 1e3+10;
int n, m;
int numb_type[len];
offer offers[len];
bool check_valid(int due_date) {
    vector<int> last_day_sale(n+1, 0);
    for (int i = 1; i <= m; i++) {
        int day = offers[i].day;
        int type = offers[i].type;
        if (day <= due_date && day > 0) {
            last_day_sale[type] = max(last_day_sale[type], day);
        }
    }
    vector<vector<int>> type_on_sale(due_date+1);
    for (int i = 1; i <= n; i++) {
        int type = i;
        int day = last_day_sale[type];
        if (day > 0) {
            type_on_sale[day].push_back(type);
        }
    }
    vector<int> need_to_buy(n+1,0);
    for (int i = 1; i <= n; i++) need_to_buy[i] = numb_type[i];
    int earned_money = 0;
    for (int i = 1; i <= due_date; i++) {
        earned_money += 1;
        for (int type : type_on_sale[i]) {
            int paid_money = min(earned_money, need_to_buy[type]);
            earned_money -= paid_money;
            need_to_buy[type] -= paid_money;
        }
    }
    int paid_without_discount = 0;
    for (int i = 1; i <= n; i++) {
        paid_without_discount += 2 * need_to_buy[i];
    }
    return earned_money >= paid_without_discount;
}
void solve(void) {
    cin >> n >> m;
    int max_numb = 0;
    for (int i = 1; i <= n; i++) {
        cin >> numb_type[i];
        max_numb = max(max_numb, numb_type[i]);
    }
    for (int i = 1; i <= m; i++) {
        cin >> offers[i].day >> offers[i].type;
    }
    int left = 1;
    int right = 2 * n * max_numb;
    int ret = -1;
    while (left <= right) {
        int mid = (left+right)>>1;
        if (check_valid(mid)) {
            ret = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}






