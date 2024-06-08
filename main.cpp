#include <bits/stdc++.h>
#define ll long long

using namespace std;

long double ln(const string &P) {
    stringstream ss;
    long double temp;
    if(P.size() < 14) {
        ss << P;
        ss >> temp;
        return log(temp);
    }

    ss << P.substr(0,13);
    ss >> temp;

    return log(temp) + (int)(P.size()-13) * log(10);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG
    
    string P;
    cin >> P;
    vector<long double> X;
    X.resize(1e5+1);

    for(int i = 1; i <= 1e5; i++) {
        X[i] = X[i-1] + log(i);
    }

    long double ln_p = ln(P);

    for(int i = 1, j = 1; i <= 1e5; i++) {
        while(X[j]-X[i-1] + 1e-9 < ln_p) j++;
        if(X[j]-X[i-1]-ln_p <= 1e-9) {
            cout << i << " " << j << endl;
            return 0;
        }
    }

    return 0;
}
