#include <bits/stdc++.h>

#define ll long long

using namespace std;

int N,L,D;
ll res = 0;
vector<int> H;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG

    cin >> N >> L >> D;
    H.resize(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> H[i];
    }

    deque<int> ma, mi;
    for(int i = 1, j = 1; i <= N; i++) {
        while(!ma.empty() && H[ma.back()] <= H[i]) ma.pop_back();
        while(!mi.empty() && H[mi.back()] >= H[i]) mi.pop_back();
        ma.push_back(i); mi.push_back(i);

        while(!ma.empty() && !mi.empty() && H[ma.front()] - H[mi.front()] > D) {
            j++;
            if(!ma.empty() && ma.front() < j) ma.pop_front();
            if(!mi.empty() && mi.front() < j) mi.pop_front();
        }

        if(i-j >= L) {
            res += (i-j-L+1);
        } 
    }

    cout << res << endl;

    return 0;
}
