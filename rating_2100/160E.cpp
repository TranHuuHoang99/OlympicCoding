/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-05-17 22:24:57
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Event {
    int u, v, w, id;
};
const int N = 8e5+10;
int n, m;
vector<Event> bus;
vector<Event> pas;
vector<int> store;
// store multiple passenger if they have common right position
priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq[N];
int pos[N];
int ret[N];
pair<int,int> it[4*N]; // store left position and id
void update(int idx, int left, int right, int pos, pair<int,int> val) {
    if (left > pos || right < pos) return;
    if (left == right) {
        it[idx] = val;
        return;
    }
    int mid = (left+right)/2;
    update(idx*2, left, mid, pos, val);
    update(idx*2+1, mid+1, right, pos, val);
    it[idx] = max(it[idx*2], it[idx*2+1]);
}
pair<int,int> query(int idx, int left, int right, int u, int v) {
    if (u > right || v < left) return {INT32_MIN, -1};
    if (u <= left && right <= v) return it[idx];
    int mid = (left+right)/2;
    pair<int,int> left_val = query(idx*2, left, mid, u, v);
    pair<int,int> right_val = query(idx*2+1, mid+1, right, u, v);
    return max(left_val, right_val);
}
void solve(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        bus.push_back((Event){u, v, w, i});
        store.push_back(u);
        store.push_back(v);
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        pas.push_back((Event){u, v, w, i});
        store.push_back(u);
        store.push_back(v);
    }
    sort(store.begin(), store.end());
    store.erase(unique(store.begin(), store.end()), store.end());
    auto compressed = [&] (int x) {
        return lower_bound(store.begin(), store.end(), x) - store.begin();
    };
    int len = store.size();
    for (Event& b : bus) {
        b.u = compressed(b.u);
        b.v = compressed(b.v);
    }
    for (Event& p : pas) {
        p.u = compressed(p.u);
        p.v = compressed(p.v);
        pos[p.id] = p.v;
    }
    auto cmp = [&] (Event a, Event b) -> bool {
        return a.w < b.w;
    };
    sort(bus.begin(), bus.end(), cmp);
    sort(pas.begin(), pas.end(), cmp);
    int index = 0;
    fill(it, it+4*(len+5), make_pair(INT32_MIN, -1));
    fill(ret, ret+m+10, -1);
    for (Event eb : bus) {
        int curtime = eb.w;
        while (index < m && pas[index].w <= curtime) {
            const Event passenger = pas[index];
            pq[passenger.v].push({passenger.u, passenger.id});
            update(1, 1, len, passenger.v, pq[passenger.v].top());
            index++;
        }
        while (true) {
            pair<int,int> passenger = query(1, 1, len, eb.u, eb.v);
            if (passenger.first < eb.u) break;
            int right = pos[passenger.second];
            ret[passenger.second] = eb.id;
            if (!pq[right].empty()) pq[right].pop();
            if (!pq[right].empty()) {
                update(1, 1, len, right, pq[right].top());
            } else {
                update(1, 1, len, right, {INT32_MIN, -1});
            }
        }
    }
    for (int i = 1; i <= m; i++) cout << ret[i] << ' ';
    cout << "\n";
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





