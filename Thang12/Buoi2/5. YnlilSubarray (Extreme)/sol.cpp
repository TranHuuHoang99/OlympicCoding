#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;
const int inf = 1000000007;
const int SHIFT = 200000; 
int n, k, numQueries;
int a[200005];
long long c[200005];
int cnt[400005];
int nxt[200005], prv[200005];
i128 ans[200005];
vector <pair <int, int>> save_l[200005], save_r[200005];
vector <int> save_prev[200005], save_next[200005]; 
vector <i128> f1, f2, f3, f4;
void preProcess() {
  multiset <int> myset; 
  for (int i = 1; i <= k; i++) {
    if (cnt[a[i]] > 0) {
      myset.erase(myset.find(cnt[a[i]])); 
    }
    cnt[a[i]]++; 
    myset.insert(cnt[a[i]]); 
  }
  int l = 1, r = k; 
  while (r <= n) {
    multiset <int>::iterator it = myset.end();
    it--; 
    c[l] = k - (*it);
    if (r == n) {
      break; 
    } 
    myset.erase(myset.find(cnt[a[l]]));
    cnt[a[l]]--; 
    if (cnt[a[l]] > 0) {
      myset.insert(cnt[a[l]]); 
    }
    l++; 
    if (cnt[a[r + 1]] > 0) {
      myset.erase(myset.find(cnt[a[r + 1]])); 
    }
    cnt[a[r + 1]]++; 
    myset.insert(cnt[a[r + 1]]); 
    r++; 
  }                                         
  stack <int> mystack; 
  c[0] = -1;
  mystack.push(0);
  n = n - k + 1; 
  for (int i = 1; i <= n; i++) {
    while (mystack.empty() == false && c[mystack.top()] > c[i]) {
      mystack.pop(); 
    }
    prv[i] = mystack.top();
    mystack.push(i); 
  }
  while (mystack.empty() == false) {
    mystack.pop(); 
  }   
  c[n + 1] = -1; 
  mystack.push(n + 1); 
  for (int i = n; i >= 1; i--) {
    while (mystack.empty() == false && c[mystack.top()] >= c[i]) {
      mystack.pop(); 
    }
    nxt[i] = mystack.top(); 
    mystack.push(i); 
  }
  for (int i = 1; i <= n; i++) {
    if (1 <= prv[i] && prv[i] <= n) {
      save_prev[prv[i]].push_back(i); 
    }
    if (1 <= nxt[i] && nxt[i] <= n) {
      save_next[nxt[i]].push_back(i); 
    }
  }
}
void init() {
  for (int i = 1; i <= n; i++) {
    f1[i] = f2[i] = f3[i] = f4[i] = 0LL; 
  }
}
void update(int index, const long long &value, vector <i128> &f) {
  for (; index <= n; index += index & -index) {
    f[index] += value; 
  }
}
long long get(int index, const vector <i128> &f) {
  long long ret = 0LL;
  for (; index > 0; index -= index & -index) {
    ret += f[index];
  }
  return ret; 
}
void computeFirst() {
  // sum of c[i] * (i - L + 1) * (R - i + 1) = sum of -c[i] * i^2  + sum of c[i] * i * (L + R) - sum of c[i] * (L - 1) * (R + 1)
  init(); 
  for (int i = 1; i <= n; i++) {
    f1[i] = f1[i - 1] + (i128) (-c[i]) * i * i;
    f2[i] = f2[i - 1] + (i128) c[i] * i;
    f3[i] = f3[i - 1] + (i128) (-c[i]);    
  }
  for (int l = 1; l <= n; l++) {
    for (auto [r, id]: save_r[l]) {
      ans[id] += (i128) (f1[r] - f1[l - 1]);
      ans[id] += (i128) (l + r) * (f2[r] - f2[l - 1]);  
      ans[id] += (i128) (l - 1) * (r + 1) * (f3[r] - f3[l - 1]); 
    }
  }
}
void computeSecond() {
  // sum of c[i] * (prev[i] - L + 1) * (R - i + 1) with prev[i] >= L = (c[i] * prev[i] - c[i] * (L - 1)) * (R - i + 1)
  // = -i * c[i] * prev[i] + i * c[i] * (L - 1) + c[i] * prev[i] * (R + 1) - c[i] * (L - 1) * (R + 1)
  init(); 
  for (int l = n; l >= 1; l--) {
    for (auto j: save_prev[l]) {
      update(j, c[j] * (-j) * prv[j], f1);
      update(j, c[j] * j, f2);
      update(j, c[j] * prv[j], f3); 
      update(j, -c[j], f4); 
    }
    for (auto [r, id]: save_r[l]) {
      ans[id] -= (i128) (get(r, f1) - get(l - 1, f1));
      ans[id] -= (i128) (l - 1) * (get(r, f2) - get(l - 1, f2)); 
      ans[id] -= (i128) (r + 1) * (get(r, f3) - get(l - 1, f3)); 
      ans[id] -= (i128) (l - 1) * (r + 1) * (get(r, f4) - get(l - 1, f4)); 
    }
  }
}
void computeThird() {
  // sum of c[i] * (i - L + 1) * (R - next[i] + 1) with next[i] <= R = (c[i] * i - c[i] * (L - 1)) * (R - next[i] + 1) 
  // = -c[i] * i * next[i] + next[i] * c[i] * (L - 1) + c[i] * i * (R + 1) - c[i] * (L - 1) * (R + 1)
  init(); 
  for (int r = 1; r <= n; r++) {
    for (auto j: save_next[r]) {
      update(j, (-c[j]) * j * nxt[j], f1);
      update(j, c[j] * nxt[j], f2); 
      update(j, c[j] * j, f3); 
      update(j, -c[j], f4);
    }
    for (auto [l, id]: save_l[r]) {
      ans[id] -= (i128) (get(r, f1) - get(l - 1, f1)); 
      ans[id] -= (i128) (l - 1) * (get(r, f2) - get(l - 1, f2));
      ans[id] -= (i128) (r + 1) * (get(r, f3) - get(l - 1, f3)); 
      ans[id] -= (i128) (l - 1) * (r + 1) * (get(r, f4) - get(l - 1, f4));
    }
  }  
}
void computeFourth() {
  // sum of c[i] * (prev[i] - L + 1) * (R - next[i] + 1) with L <= prev[i] <= next[i] <= R
  // = -c[i] * prev[i] * next[i] + c[i] * prev[i] * (R + 1) + c[i] * next[i] * (L - 1) - c[i] * (L - 1) * (R + 1)
  init();
  for (int l = n; l >= 1; l--) {
    for (auto j: save_prev[l]) {
      update(nxt[j], (-c[j]) * prv[j] * nxt[j], f1); 
      update(nxt[j], c[j] * prv[j], f2); 
      update(nxt[j], c[j] * nxt[j], f3); 
      update(nxt[j], -c[j], f4); 
    }
    for (auto [r, id]: save_r[l]) {
      ans[id] += (i128) (get(r, f1) - get(l - 1, f1)); 
      ans[id] += (i128) (r + 1) * (get(r, f2) - get(l - 1, f2)); 
      ans[id] += (i128) (l - 1) * (get(r, f3) - get(l - 1, f3)); 
      ans[id] += (i128) (l - 1) * (r + 1) * (get(r, f4) - get(l - 1, f4)); 
    }
  }
}
int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k >> numQueries;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
      a[i] -= i;
      a[i] += SHIFT;  
      cnt[a[i]] = 0; 
      save_r[i].clear(); 
      save_l[i].clear();
      save_prev[i].clear(); 
      save_next[i].clear(); 
    }
    preProcess();
    for (int query = 1; query <= numQueries; query++) {
      ans[query] = 0LL; 
      int l, r;
      cin >> l >> r;
      r = r - k + 1; 
      save_r[l].push_back(make_pair(r, query));
      save_l[r].push_back(make_pair(l, query));          
    }
    f1.resize(n + 1, 0LL);
    f2.resize(n + 1, 0LL);
    f3.resize(n + 1, 0LL);
    f4.resize(n + 1, 0LL);
    computeFirst();
    computeSecond();
    computeThird();
    computeFourth();
    for (int query = 1; query <= numQueries; query++) {
      cout << (long long) ans[query] << endl; 
    } 
  }
  return 0; 
}