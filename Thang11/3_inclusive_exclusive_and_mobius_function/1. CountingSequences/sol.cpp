#include <iostream> 
const long long mod = 1000000007LL; 
long long fact[100005], inv_fact[100005]; 
int n, k;

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

void init() {
  fact[0] = 1LL; 
  inv_fact[0] = 1LL;
  for (int i = 1; i <= 1000000; i++) {
    fact[i] = (fact[i - 1] * (long long) i) % mod; 
    inv_fact[i] = fastpow(fact[i], mod - 2); 
  }
}

long long C(int n, int k) {
  long long ret = fact[n]; 
  (ret *= inv_fact[k]) %= mod; 
  (ret *= inv_fact[n - k]) %= mod; 
  return ret; 
}

int main () {
  init();
  std::cin >> n >> k;
  long long ret = 0LL;
  for (int i = k; i >= 1; i--) {
    long long ways = C(k, k - i);
    (ways *= fastpow(i, n)) %= mod;
    if ((k - i) % 2 == 1) {
      ret -= ways; 
      (ret += mod) %= mod; 
    }    
    else {
      (ret += ways) %= mod; 
    }
  } 
  std::cout << ret; 
  return 0; 
}