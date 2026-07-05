/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-07-05 21:21:02
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

/*
    in this function we want b must be the area inside the result area
    that we want to find.
    if we choose b to be the child area inside the result area and form the
    child rectangle, there are several condition
    - we find the division of child area so that we can determine child's width
    and child's height
    - we also want to check if child's width is <= result area's width
    and child's height is also <= result area's height
    let's say
        - area of child is : j * (B/j)
        - area of result is : i * ((A+B) / i)
        - j <= i and (B/j <= (A+B)/i)
    if condition was satisfied => we found answer
    notice: to get the minimum perimeter we have to make the result rectangle
    shaped closely to the square
    - to make the square we have to maximum the width length of child rectangle
 */
int min_val(int a, int b) {
    vector<int> len;
    int k = 0;
    for (int i = 1; i * i <= b; i++) {
        if (b % i == 0) {
            len.push_back(i);
            k++;
        }
    }
    int ret = 2 * (a + b + 1ll);
    int area = a + b;
    int j = 0;
    for (int i = 1; i * i <= area; i++) {
        if (area % i == 0) {
            while (j + 1 < k && len[j+1] <= i) {
                j++;
            }
            if (b / len[j] <= area / i) {
                ret = min(ret, (i + area / i) * 2);
            }
        }
    }
    return ret;
}
void solve(void) {
    int a, b;
    cin >> a >> b;
    int ret = min(min_val(a, b), min_val(b, a));
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





