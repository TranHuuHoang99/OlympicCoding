#include <iostream> 
#include <math.h>
#include <algorithm> 
#include <utility>
#include <vector> 
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
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long a, n, b, m; 
    std::cin >> a >> n >> b >> m; 
    long long gcd = std::__gcd(n, m); 
    if ((a - b) % gcd != 0) {
      std::cout << "no solution" << std::endl;
      continue;   
    }
    long long lcm = n * m / gcd; 
    std::vector <std::pair <int, int>> save; 
    for (int p = 2; p <= (long long) std::sqrt(std::max(n, m)); p++) {
      int cntn = 0; 
      int cntm = 0; 
      while (n % p == 0) {
        cntn++; 
        n /= p; 
      }
      while (m % p == 0) {
        cntm++;
        m /= p;
      }
      if (cntn == 0 && cntm == 0) {
        continue; 
      }
      int pn = 1, pm = 1; 
      for (int i = 1; i <= cntn; i++) {
        pn *= p; 
      }
      for (int i = 1; i <= cntm; i++) {
        pm *= p; 
      }
      if (pn > pm) {
        save.push_back(std::make_pair(pn, a % pn));   
      }
      else {
        save.push_back(std::make_pair(pm, b % pm)); 
      }
    }
    if (n > 1) {
      save.push_back(std::make_pair(n, a % n)); 
    }
    if (m > 1 && n != m) {
      save.push_back(std::make_pair(m, b % m)); 
    }
    long long M = 1; 
    for (int i = 0; i < (int) save.size(); i++) {
      M *= save[i].first; 
    }
    long long ans = 0LL; 
    for (int i = 0; i < (int) save.size(); i++) {
      long long pi = M / save[i].first;
      long long x, y;
      extendedEuclide(pi, save[i].first, x, y);
      x %= lcm; 
      if (x < 0) {
        x += lcm;
      }
      long long product = save[i].second;
      product = ((__int128) product * pi) % lcm;  
      product = ((__int128) product * x) % lcm; 
      (ans += product) %= lcm; 
    }
    std::cout << ans << ' ' << lcm << std::endl;
  }
  return 0; 
}