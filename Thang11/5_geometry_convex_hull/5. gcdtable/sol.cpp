#include <iostream>
#include <algorithm>
#include <math.h>
long long row, col; 
int n; 
long long a[10005];
void extendedEuclide(const long long &a, const long long &b, long long &x, long long &y) {
  if (b == 0) {
    x = 1; 
    y = 0; 
    return; 
  }
  long long x1, y1; 
  extendedEuclide(b, a % b, x1, y1); 
  x = y1; 
  y = x1 - (a / b) * y1; 
} 
int main() {
  std::cin >> row >> col >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  bool found = true; 
  long long lcm = 1; 
  for (int i = 1; i <= n; i++) {
    long long gcd = std::__gcd(lcm, a[i]); 
    lcm /= gcd; 
    if (row / a[i] >= lcm) {
      lcm *= a[i]; 
    }
    else {
      found = false;
      break;   
    }      
  }
  if (found == false) {
    std::cout << "NO";
    return 0; 
  }
  long long r = 0LL; 
  lcm = 1LL; 
  long long ans; 
  for (int i = 1; i <= n; i++) {
    long long curr = -(i - 1);
    curr %= a[i];
    (curr += a[i]) %= a[i];
    long long gcd = std::__gcd(lcm, a[i]);
    if (std::abs(curr - r) % gcd != 0) {
      std::cout << "NO";
      return 0;  
    }
    long long x, y;
    extendedEuclide(lcm, a[i], x, y);
    long long mod = a[i] / gcd;
    x %= mod; 
    (x += mod) %= mod; 
    long long curlcm = lcm / gcd * a[i];
    ans = ((__int128) lcm * x) % curlcm * ((curr - r) / gcd) % curlcm + r;
    ans %= curlcm;
    (ans += curlcm) %= curlcm;
    r = ans;
    lcm = curlcm;   
  }
  if (ans == 0) {
    ans += lcm; 
  }                 
  if (ans + n - 1 <= col) {
    for (int i = 1; i <= n; i++) {
      long long gcd = std::__gcd(ans + i - 1, lcm);
      if (gcd != a[i]) {
        std::cout << "NO";
        return 0;
      }
    }  
    std::cout << "YES";
  }
  else {
    std::cout << "NO"; 
  }
  return 0; 
}