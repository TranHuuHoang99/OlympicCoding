#include <iostream> 
#include <vector>
#include <math.h> 
const long long mod = 1000000007LL;  
int numTest; 
int n; 
long long inv[100005]; 
long long mulValue[100005]; 
int mu[100005]; 
long long f[100005]; 
int a[505]; 
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
  for (int i = 1; i <= 100000; i++) {
    inv[i] = fastpow(i, mod - 2); 
  }
  mu[1] = 1;
  for (int i = 1; i <= 100000; i++) {
    for (int j = 2 * i; j <= 100000; j += i) {
      mu[j] -= mu[i]; 
    }
  }
  for (int i = 1; i <= 100000; i++) {
    for (int j = i; j <= 100000; j += i) {
      (f[j] += ((long long) i * mu[j / i] + mod) % mod) %= mod; 
    }
  }                      
}
void update(int l, int r, const long long &x) {
  (mulValue[l] *= x) %= mod; 
  (mulValue[r + 1] *= inv[x]) %= mod; 
}

int main () {
  init(); 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int maxValue = -1;
    int minValue = 100005; 
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
      maxValue = std::max(maxValue, a[i]); 
      minValue = std::min(minValue, a[i]); 
    }  
    for (int i = 1; i <= maxValue; i++) {
      mulValue[i] = 1LL; 
    }
    for (int i = 1; i <= n; i++) {
      int sqrtValue = (int) std::sqrt(a[i]);
      for (int j = 1; j <= sqrtValue; j++) {
        update(j, j, a[i] / j);   
      } 
      for (int j = 1; j <= sqrtValue; j++) {
        int r = a[i] / j; 
        int l = std::max(sqrtValue + 1, a[i] / (j + 1) + 1); 
        if (l <= r) {
          update(l, r, j); 
        }
      }
    }
    for (int i = 2; i <= maxValue; i++) {
      (mulValue[i] *= mulValue[i - 1]) %= mod; 
    }
    long long ans = 0LL; 
    for (int d = 1; d <= minValue; d++) {
      (ans += (mulValue[d] * f[d]) % mod) %= mod;   
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}