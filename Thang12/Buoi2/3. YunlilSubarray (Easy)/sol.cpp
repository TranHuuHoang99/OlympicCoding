#include <iostream>
#include <set>
const int SHIFT = 200000; 
int n, k, numQueries;
int a[200005];
int c[200005];
int cnt[400005];   
void preProcess() {
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
    c[l] = *it;
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
}
int main () {
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
      std::cout << k - c[l] << std::endl; 
    } 
  }
  return 0; 
}