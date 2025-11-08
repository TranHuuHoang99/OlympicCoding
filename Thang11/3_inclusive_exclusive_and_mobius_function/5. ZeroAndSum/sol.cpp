#include <iostream>
const long long mod = 998244353LL; 
long long fact[(1 << 20) + 5], inv_fact[(1 << 20) + 5], inv[(1 << 20) + 5]; 
int a[(1 << 20) + 5]; 
long long f[(1 << 20) + 5]; 
long long fastpow(const long long &x, const long long &n) {
  if (n == 0) {
    return 1LL; 
  }
  long long ret = fastpow(x, n / 2);
  (ret *= ret) %= mod;
  if (n % 2 == 1) {
    (ret *= x) %= mod; 
  }
  return ret;
}
int n, k; 
int main () {
  fact[0] = 1LL; 
  inv_fact[0] = 1LL;
  for (int i = 1; i <= (1 << 20); i++) {
    fact[i] = (fact[i - 1] * i) % mod; 
    inv_fact[i] = fastpow(fact[i], mod - 2); 
    inv[i] = fastpow(i, mod - 2); 
  }
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      f[a[i]]++;  
    }
    for (int i = 0; i < k; i++) {
      for (int mask = 0; mask < (1 << k); mask++) {
        if ((mask & (1 << i)) == 0) {
          f[mask] += f[mask | (1 << i)]; 
        }
      }
    }
    long long ans = 0LL; 
    for (int mask = 1; mask < (1 << k); mask++) {
      int numb = f[mask];
      if (numb == 0) {
        continue; 
      }
      int cnt = (int) __builtin_popcount(mask); 
      long long mul = numb;
      (mul *= inv[n - numb + 1]) %= mod; 
      if (cnt % 2 == 1) {
        (ans += mul) %= mod;
      } 
      else {
        ans -= mul;
        (ans += mod) %= mod; 
      }
    }
    (ans *= fact[n]) %= mod; 
    for (int mask = 0; mask < (1 << k); mask++) {
      f[mask] = 0; 
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}
