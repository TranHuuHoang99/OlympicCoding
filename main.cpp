#include <bits/stdc++.h>
#include <memory>

using namespace std;

int n = 0;
int ret = 0;

void solve(vector<int> numbs) {
    if(numbs[3] > numbs[0]) {
        numbs[0] = 0;
    } else {
        numbs[0] -= numbs[3];
    }

    if(numbs[2] > numbs[1]) {
        ret += numbs[2];
        numbs[2] -= numbs[1];
        numbs[0] -= ((5-3)*numbs[2]);
    } else if(numbs[2] == numbs[1]) {
        ret += numbs[2];
    } else {
        ret += numbs[2];
        numbs[1] -= numbs[2];
        if(numbs[1] >= 2) {
            if(numbs[1] % 2 == 0) {
                numbs[0] -= (numbs[1] / 2);
                ret += (numbs[1]/2);
            } else {
                numbs[0] -= ((numbs[1]/2) + 3);
                ret += ((numbs[1]/2)+1);
            }
        } else {
            numbs[0] -= 3;
            ret++;
        }
    }

    if(numbs[0] > 0) {
        if(numbs[0] > 5) {
            ret = numbs[0] % 5 == 0 ? (ret+(numbs[0]/5)) : (ret+(numbs[0]/5)+1);
        } else {
            ret += 1;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> numbs(5,0);

    for(int i = 0; i < 5; i++) {
        cin >> numbs[i];
        if(i == 3 || i == 4) ret += numbs[i];
    }

    solve(numbs);

    cout << ret << endl;

    return 0;
}

