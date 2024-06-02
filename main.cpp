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
    ll K;
    cin >> N >> K;
    map<ll,int> A;
    vector<ll> arr(N);

    ll temp;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        A[temp] += 1;
        arr[i] = temp;
    }

    auto it = unique(arr.begin(), arr.begin()+N);
    arr.resize(distance(arr.begin(), it));

    int i = 0, j = arr.size()-1;

    int ret = 0;

    while(i < j) {
        ll sum = arr[i]+arr[j];
        if(sum < K) {
            i++;
        } else if(sum > K) {
            j--;
        } else {
            ret += (A[arr[i]]*A[arr[j]]);
            i++;
            j--;
        }
    }

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i]*2 == K) {
            int count = A[arr[i]];
            ret += (count*(count-1)/2);
        }
    }

    cout << ret << endl;
    
    return 0;
}
