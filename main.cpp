#include <bits/stdc++.h>

using namespace std;

int n = 0;

int runCase(vector<int> arr) {
    int ret = INT32_MIN;
    int sum = 0;    
    int temp_sum = INT32_MIN;
    int temp = 0;

    for(int i = 0; i < n; i++) {
        if(i+2 < n) {
            sum = arr[i] + arr[i+1] + arr[i+2];
        }

        if(sum > ret) {
            ret = sum;
        }

        if(arr[i] > ret) {
            ret = arr[i];
        }

        temp += arr[i];
        if(temp > temp_sum) {
            temp_sum = temp;
        }

        if(temp < 0) {
            temp = 0;
        }

        if(temp_sum > ret) {
            ret = temp_sum;
        }
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << runCase(arr) << endl;

    return 0;
}

