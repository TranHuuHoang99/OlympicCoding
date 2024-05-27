#include <bits/stdc++.h>

#define ll long long
    
using namespace std;
  
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG
    
    int N;
    cin >> N;
    multiset<ll> cubes;
    ll temp;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        auto it = cubes.upper_bound(temp);
        if(it != cubes.end()) {
            cubes.erase(it);
        }

        cubes.insert(temp);
    }

    cout << cubes.size() << endl;

    return 0;
}