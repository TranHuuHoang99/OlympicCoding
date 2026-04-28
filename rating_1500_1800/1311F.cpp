/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-04-28 20:44:08
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
    int dist = 0;
    int numb = 0;
};
const int N = 2e5+10;
int n;
pair<int,int> A[N];
Node it[4*N];
map<int,int> save;
void update(int idx, int left, int right, int pos, int val) {
    if (left > pos || right < pos) return;
    if (left == right) {
        if (left == pos) {
            it[idx].dist += val;
            it[idx].numb += 1;
            return;
        }
    }
    int mid = (left+right)/2;
    update(idx*2, left, mid, pos, val);
    update(idx*2+1, mid+1, right, pos, val);
    it[idx].dist = it[idx*2].dist + it[idx*2+1].dist;
    it[idx].numb = it[idx*2].numb + it[idx*2+1].numb;
}
Node get_val(int idx, int left, int right, int u, int v) {
    if (u > right || v < left) return (Node){0,0};
    if (u <= left && right <= v) {
        return it[idx];
    }
    int mid = (left+right)/2;
    Node ret;
    Node left_node = get_val(idx*2, left, mid, u, v);
    Node right_node = get_val(idx*2+1, mid+1, right, u, v);
    ret.dist = left_node.dist + right_node.dist;
    ret.numb = left_node.numb + right_node.numb;
    return ret;
}
bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i].first;
    vector<int> arr;
    for (int i = 1; i <= n; i++) {
        cin >> A[i].second;
        arr.push_back(A[i].second);
    }
    sort(arr.begin(), arr.end());
    int cnt = 1;
    for (int temp : arr) {
        auto it = save.find(temp);
        if (it == save.end()) {
            save[temp] = cnt;
            cnt++;
        }
    }
    sort(A+1, A+1+n, cmp);
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        int location = A[i].first;
        int val = A[i].second;
        int velocity = save[val];
        Node temp = get_val(1, 1, n, 1, velocity);
        ret += location * temp.numb - temp.dist;
        update(1, 1, n, velocity, location);
    }
    cout << ret << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





