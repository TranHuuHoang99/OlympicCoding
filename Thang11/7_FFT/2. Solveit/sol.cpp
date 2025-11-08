#include <iostream>
#include <math.h>
#include <iomanip>

double f(double p, double q, double r, double s, double t, double u, double x) {
  return p * std::exp(-x) + q * std::sin(x) + r * std::cos(x) + s * std::tan(x) + t * x * x + u;
}

int main () {
  double p, q, r, s, t, u;
  while (std::cin >> p >> q >> r >> s >> t >> u) {
    if (f(p, q, r, s, t, u, 0.00000) < 0.00000 || f(p, q, r, s, t, u, 1.00000) > 0.0000) {
      std::cout << "No solution" << std::endl;
    }
    else {
      double lo = 0.000;
      double hi = 1.000;
      for (int i = 1; i <= 300; i++) {
        double mid = (lo + hi) / 2;
        if (f(p, q, r, s, t, u, mid) > 0.000) {
          lo = mid;
        }
        else {
          hi = mid;
        }
      }
      double res = (lo + hi) / 2;
      std::cout << std::fixed << std::setprecision(4) << res << std::endl;
    }
  }
  return 0;
}