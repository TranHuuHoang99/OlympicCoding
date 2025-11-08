#include <iostream>
#include <math.h> 
#include <algorithm>
int n;
int a[10], m[10]; 
long long mul[10], inv_mul[10];
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
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> m[i];
    int tmp = std::abs(a[i]); 
    tmp %= m[i]; 
    if (a[i] < 0) {
      tmp *= -1;
      tmp += m[i]; 
    }
    a[i] = tmp; 
  }
  long long M = m[1]; 
  for (int i = 2; i <= n; i++) {
    M *= m[i]; 
  }
  for (int i = 1; i <= n; i++) {
    mul[i] = M / m[i]; 
  }                  
  for (int i = 1; i <= n; i++) {     
    long long y; 
    extendedEuclide(mul[i], m[i], inv_mul[i], y); 
  }
  long long ans = 0LL; 
  for (int i = 1; i <= n; i++) {
    long long product = a[i];
    (product *= mul[i]) %= M;
    (product *= inv_mul[i]) %= M;
    (ans += product) %= M;   
  }
  (ans += M) %= M;
  std::cout << ans; 
  return 0; 
}