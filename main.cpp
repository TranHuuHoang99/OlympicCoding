#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ret(encoded.size()+1);
        ret[0] = first;

        for (int i = 0; i < encoded.size(); i++) {
            ret[i+1] = encoded[i] ^ ret[i];
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
