#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector> 
int guess[7] = {4, 3, 5, 7, 11, 13, 17};
const int lcm = 1021020;  
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
  int numTest, n, m;
  std::cin >> numTest >> n >> m; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long ans = 0LL; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 18; j++) {
        std::cout << guess[i] << ' '; 
      }  
      std::cout << std::endl; 
      fflush(stdout); 
      std::vector <int> a(18);
      int remainder = 0;  
      for (int j = 0; j < 18; j++) {
        std::cin >> a[j];
        (remainder += a[j]) %= guess[i];  
      }                  
      long long x, y; 
      extendedEuclide(lcm / guess[i], guess[i], x, y); 
      x %= lcm;
      if (x < lcm) {
        x += lcm; 
      }
      long long product = remainder; 
      (product *= x) %= lcm; 
      (product *= (lcm / guess[i])) %= lcm; 
      (ans += product) %= lcm; 
    }
    std::cout << ans << std::endl; 
    fflush(stdout); 
    int response; 
    std::cin >> response; 
  }
  return 0; 
}