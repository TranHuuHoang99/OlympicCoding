#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(string str) {
    vector<char> even, odd;
    string ret = "";

    for(int i = 0; i < str.size(); i++) {
        if(str[i] % 2 == 0) {
            even.push_back(str[i]);
        } else {
            odd.push_back(str[i]);
        }
    }
    
    int i = 0, j = 0;
    while(i < even.size() || j < odd.size()) {
        if(j >= odd.size() || (i < even.size() && even[i] < odd[j])) {
            ret += even[i++];
        } else {
            ret += odd[j++];
        }
    }

    cout << ret << endl;
}
  
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG

    int N;
    cin >> N;
    string str;
    for(int i = 0; i < N; i++) {
        cin >> str;
        solve(str);
    }

    return 0;
}
