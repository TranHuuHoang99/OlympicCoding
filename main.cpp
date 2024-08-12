#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (int i = 0; i < image.size(); i++) {
            for (int j = 0, k = image[i].size()-1; j < image[i].size()/2; j++) {
                swap(image[i][j], image[i][k]);
                k--;
            }
            for (int j = 0; j < image[i].size(); j++) {
                image[i][j] ^= 1;
            }
        }
        
        return image;
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
