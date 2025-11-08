#include <iostream>
int mu[1000005]; 
int cnt[1000005]; 
int n; 
 
int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x; 
    cnt[x]++; 
  }
  mu[1] = 1;
  for (int i = 1; i <= 1000000; i++) {
    for (int j = 2 * i; j <= 1000000; j += i) {
      mu[j] -= mu[i]; 
      cnt[i] += cnt[j]; 
    }
  }
  long long ans = 0LL; 
  for (int g = 1; g <= 1000000; g++) {
    ans += 1LL * cnt[g] * (cnt[g] - 1) / 2LL * mu[g];   
  }
  std::cout << ans;
  return 0; 
}
