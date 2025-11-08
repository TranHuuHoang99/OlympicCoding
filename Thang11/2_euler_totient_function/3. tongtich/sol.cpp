#include <iostream>
#include <algorithm>  
#include <map> 
int a[500005]; 
int n;
long long p, phip;  
std::map <int, int> cnt; 

long long fastpow(long long x, long long n) {
  if (n == 0) {
    return 1LL; 
  }
  long long ret = fastpow(x, n / 2); 
  (ret *= ret) %= p; 
  if (n % 2 == 1) {
    (ret *= x) %= p; 
  }
  return ret; 
}

long long inv(const long long &x) {
  return fastpow(x, phip - 1); 
}

int main () {
  std::cin >> n >> p;
  long long ans = 0LL; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
    a[i] %= p; 
    if (a[i] == 0) {  
      ans++; 
    }
  }
  ans *= ans - 1; 
  ans /= 2; 
  phip = p;
  long long tmp = p; 
  for (int i = 2; i <= 35000; i++) {
    if (tmp % i == 0) {
      phip /= i;
      phip *= i - 1; 
      while (tmp % i == 0) {
        tmp /= i;   
      }
    }
  }
  if (tmp > 1) {
    phip /= tmp;
    phip *= tmp - 1; 
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] > 1) {
      if (std::__gcd((long long) a[i] - 1, p) == 1) {
        ans += cnt[inv(a[i] - 1)]; 
      }
      cnt[a[i] - 1]++; 
    }  
  }
  std::cout << ans; 
  return 0; 
}