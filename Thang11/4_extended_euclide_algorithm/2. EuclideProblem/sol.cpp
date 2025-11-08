#include <iostream>
long long a, b; 
long long extendedEuclide(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1; 
    y = 0; 
    return a; 
  }
  long long x1, y1; 
  long long gcd = extendedEuclide(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return gcd;   
}

int main () {
  while (std::cin >> a >> b) {
    long long x, y, gcd;
    gcd = extendedEuclide(a, b, x, y);
    std::cout << x << ' ' << y << ' ' << gcd << std::endl;   
  }
  return 0; 
}