#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
vector<ll> arr;
vector<ll> ret;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    arr.assign(N+1,INT64_MAX);
    ret.assign(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    stack<pair<ll,int>> st;

    for(int i = 0; i < N; i++) {
        st.push({arr[i], i});
        while(!st.empty() && arr[i+1] > st.top().first) {
            if(arr[i+1] == INT64_MAX) {
                ret[st.top().second] = -1;
            } else {
                ret[st.top().second] = arr[i+1];
            }

            st.pop();
        }
    }

    for(auto r : ret) {
        cout << r << " ";
    }
    cout << "\n";

    return 0;
}
