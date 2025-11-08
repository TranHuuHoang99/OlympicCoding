#include <iostream> 
#include <math.h>
#include <algorithm>
int p[9] = {3, 5, 7, 16, 11, 13, 17, 19, 23}; 
const long long M = 1784742960;
long long mul[9], a[9], inv_mul[9];
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
  for (int i = 0; i < 9; i++) {
    mul[i] = M / p[i]; 
    long long y;
    extendedEuclide(mul[i], p[i], inv_mul[i], y); 
  }
  int numTest; 
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    for (int i = 1; i <= 25; i++) {
      std::cout << "? " << i << ' ' << M + i << std::endl;
      fflush(stdout);
      long long gcd;
      std::cin >> gcd;
      for (int j = 0; j < 9; j++) {
        if ((gcd % p[j]) == 0) {
          a[j] = p[j] - (i % p[j]); 
        }
      }
    }
    long long ans = 0LL;
    for (int j = 0; j < 9; j++) {
      long long product = mul[j];
      (product *= inv_mul[j]) %= M; 
      (product *= a[j]) %= M; 
      (ans += product) %= M; 
    }  
    (ans += M) %= M;
    std::cout << "! " << ans << std::endl; 
    fflush(stdout); 
  }
  return 0; 
}