#include <iostream>
#include <math.h>
#include <set>
#include <stack>
const int inf = 1000000007;
const int SHIFT = 200000; 
int n, k, numQueries;
int a[200005];
int c[200005];
int cnt[400005];
int next_pos[200005][20];
int prefix_min[200005];
long long sum[200005][20];    
void preProcess() {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 20; j++) {
      next_pos[i][j] = -1;
      sum[i][j] = 0;  
    }
  }
  std::multiset <int> myset; 
  for (int i = 1; i <= k; i++) {
    if (cnt[a[i]] > 0) {
      myset.erase(myset.find(cnt[a[i]])); 
    }
    cnt[a[i]]++; 
    myset.insert(cnt[a[i]]); 
  }
  int l = 1, r = k; 
  while (r <= n) {
    std::multiset <int>::iterator it = myset.end();
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
  c[n - k + 2] = -1; 
  std::stack <int> mystack; 
  mystack.push(n - k + 2); 
  for (int i = n - k + 1; i >= 1; i--) {
    while (mystack.empty() == false && c[mystack.top()] >= c[i]) {
      mystack.pop(); 
    }
    next_pos[i][0] = mystack.top(); 
    sum[i][0] = (long long) c[i] * (mystack.top() - i);
    mystack.push(i);
  }                        
  for (int j = 1; j <= 19; j++) {
    for (int i = 1; i <= n - k + 1; i++) {
      int p = next_pos[i][j - 1];
      if (p != -1) {
        next_pos[i][j] = next_pos[p][j - 1];
        sum[i][j] = sum[i][j - 1] + sum[p][j - 1];  
      }
    }
  }                    
}
int main() {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k >> numQueries;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
      a[i] -= i;
      a[i] += SHIFT;  
      cnt[a[i]] = 0; 
    }
    preProcess();
    for (int query = 1; query <= numQueries; query++) {
      int l, r;
      std::cin >> l >> r;
      long long ans = 0LL; 
      int p = l;
      for (int j = 19; j >= 0; j--) {
        if (next_pos[p][j] != -1 && next_pos[p][j] <= r - k + 1) {
          ans += sum[p][j];
          p = next_pos[p][j];    
        }
      }
      ans += (long long) c[p] * (r - k + 1 - p + 1);
      std::cout << ans << std::endl;           
    } 
  }
  return 0; 
}