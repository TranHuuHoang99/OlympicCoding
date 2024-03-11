#include <bits/stdc++.h>

using namespace std;

vector<int> A;
vector<int> B;

int n = 0, m = 0;

bool compare(pair<int,int> a, pair<int,int> b) {
    if(a.first > b.first) {
        return true;
    } else if(a.first == b.first) {
        return a.second <= b.second;
    } else {
        return false;
    }

    return false;
}

pair<int,int> solve(void) {
    vector<int> temp;
    vector<pair<int,int>> ret;
    for(int i = 0; i < n; i++) {
        temp = B;
        temp[i] = 0;
        vector<int> C(n, 0);
        for(int j = 0; j < n; j++) {
            C[j] = A[j] + temp[j];
        }

        sort(C.begin(), C.end());

        int payment = 0;
        int k = 0;
        while(payment < m && k < n) {
            payment += C[k];
            if(payment > m) {
                ret.push_back(pair<int,int>(k, payment-C[k]));
            } else if(payment == m) {
                ret.push_back(pair<int,int>(k+1, payment));
            } else if(k >= n-1) {
                ret.push_back(pair<int,int>(k+1, payment));
            }
            
            k++;
        }
    }

    sort(ret.begin(), ret.end(), compare);

    return ret[0];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    A.assign(n, 0);
    B.assign(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> B[i];
    }

    cout << solve().first << " " << solve().second << endl;

    return 0;
}
