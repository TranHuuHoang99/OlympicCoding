#include <iostream>
const long long mod = 1000000007LL;
long long derangement[100005];
long long fact[100005], invFact[100005];
int numTest, N;
long long fastpow(long long x, long long n) {
  if (n == 0) {
    return 1;
  }
  long long ret = fastpow(x, n / 2);
  (ret *= ret) %= mod;
  if (n % 2 == 1) {
    (ret *= x) %= mod;
  }
  return ret;
}
void init() {
  fact[0] = 1;
  invFact[0] = 1;
  for (int i = 1; i < 100005; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    invFact[i] = fastpow(fact[i], mod - 2);
  }
  derangement[0] = 0;
  derangement[1] = 0;
  derangement[2] = 1;
  derangement[3] = 2;
  for (int i = 4; i < 100005; i++) {
    derangement[i] = 1LL * (i - 1) * (derangement[i - 1] + derangement[i - 2]) % mod;
  }
}
long long C(int n, int k) {
  long long res = fact[n];
  (res *= invFact[k]) %= mod;
  (res *= invFact[n - k]) %= mod;
  return res;
}
int main () {
  init();
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> N;
    long long res = C(N, N / 2);
    (res *= fact[N / 2]) %= mod;
    (res *= derangement[N / 2]) %= mod;
    std::cout << res << std::endl;
  }
  return 0;
}