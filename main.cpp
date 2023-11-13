#include <bits/stdc++.h>

#define GET_MAX(a, b) (a > b ? a : b)
#define GET_MIN(a ,b) (a < b ? a : b)

using namespace std;

int n = 0;
int goods[10] = {1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000};
vector<int> res;

int runCase(vector<int> boxes) {
    int ret = 0;
    int temp = 0;
    int next = 0;

    for(int i = 0; i < 10; i++) {
        temp = 0;
        for(int j = boxes[i]; j >= 0; j--) {
            if(i+1 >= 10) {
                if(n - (j*goods[i]) == 0) {
                    temp = j;
                    break;
                } else {
                    continue;
                }
            }

            for(int k = i+1; k < 10; k++) {
                if(boxes[k] > 0) {
                    next = k;
                    break;
                }
            }

            if(n - (j*goods[i]) >= 0 && (n - (j*goods[i])) % goods[next] == 0) {
                temp = j;
                break;
            }
        }

        n -= (temp*goods[i]);
        res.push_back(temp);
        ret += temp;
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> boxes(10);

    cin >> n;
    for(int i = 0; i < 10; i++) {
        cin >> boxes[i];
    }

    cout << runCase(boxes) << endl;

    const char *end = " ";
    
    for(int i = 0; i < 10; i++) {
        if(i == 9) {
            end = "\n";
        }

        if(i < res.size()) {
            cout << res[i] << end;
        } else {
            cout << 0 << end;
        }
    }

    return 0;
}
