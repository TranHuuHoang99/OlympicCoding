#include <bits/stdc++.h>

using namespace std;

int n = 0;
int m = 0;
int sum  = 0;

int expand(int index, int length, vector<int> arr) {
    int left = index - 1;
    int right = length % 2 == 0 ? index : index + 1;
    int temp_sum = sum;

    if(length % 2 != 0) {
        temp_sum -= arr[index];
    }

    while(left >= (index - (length/2))) {
        temp_sum -= arr[left];
        temp_sum -= arr[right];

        left--;
        right++;
    }

    if(temp_sum == 0) {
        return 1;
    } else if(temp_sum == -length) {
        return 1;
    }

    return 0;
}

int runCase(vector<int> arr) {
    int ret = 0;

    for(int i = (m/2); i < n - (m/2); i++) {
        ret += expand(i, m, arr);
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> m;
    vector<int> arr(n);
    vector<int> virus(m);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> virus[i];
        sum += virus[i];
    }

    cout << runCase(arr) << endl;

    return 0;
}

