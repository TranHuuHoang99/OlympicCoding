#include <iostream> 
#include <algorithm>
#include <math.h>
long long n, m, a, k;
void extendedEuclide(long long a, long long b, long long &x, long long &y) {
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

int main () {
  while (true) {
    std::cin >> n >> m >> a >> k; 
    if (n == 0 && m == 0 && a == 0 && k == 0) {
      break; 
    }
    a = -a; 
    long long g = std::__gcd(m, a); 
    long long c = k - n; 
    if (c % g != 0) {
      std::cout << "Impossible" << std::endl; 
      continue; 
    }
    long long x, y;                            
    extendedEuclide(m, a, x, y); 
    g = m * x + a * y; 
    if (g < 0) {
      g = -g;
      x = -x; 
      y = -y; 
    }
    x *= c / g;
    y *= c / g; 
    long long lim1 = (g - g * y) / m;
    if ((g > g * y) && (g - g * y) % m != 0) {
      lim1++; 
    }
    long long lim2 = (-g * x) / (-a);
    if ((-g * x > 0) && (-g * x) % (-a) != 0) {
      lim2++; 
    } 
    long long t = std::max(lim1, lim2); 
    x -= t * (a / g); 
    std::cout << n + m * x << std::endl; 
  }
  return 0; 
}                      