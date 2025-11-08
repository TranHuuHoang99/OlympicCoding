#include <iostream> 
const long long mod = 1000000007LL; 
long long power2[1000005]; 
const int MAX_BIT = 21; 
int f[(1 << MAX_BIT) + 2][MAX_BIT + 2]; 
int n; 

int main() {
  std::cin >> n;
  power2[0] = 1LL;
  for (int i = 1; i <= n; i++) {
    power2[i] = (power2[i - 1] * 2LL) % mod; 
  }
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x; 
    f[x][0]++; 
  }                  
  for (int j = 1; j <= MAX_BIT; j++) {
    for (int mask = 0; mask < (1 << MAX_BIT); mask++) {
      int bit = ((mask & (1 << (j - 1))) > 0);
      f[mask][j] = f[mask][j - 1]; 
      if (bit == 0) {
        f[mask][j] += f[mask + (1 << (j - 1))][j - 1]; 
      } 
    }  
  }
  long long ans = 0LL; 
  for (int mask = 0; mask < (1 << MAX_BIT); mask++) {
    int countBit = (int) __builtin_popcount(mask); 
    if (countBit % 2 == 0) {
      (ans += (power2[f[mask][MAX_BIT]] - 1)) %= mod; 
    }
    else {
      ans -= power2[f[mask][MAX_BIT]] - 1; 
      (ans += mod) %= mod; 
    }
  }
  std::cout << ans;
  return 0; 
}