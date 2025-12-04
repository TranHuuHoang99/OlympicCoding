#include <iostream>
#include <utility>
#include <math.h> 
long long n, k; 
std::pair <long long, long long> f(long long x) {
  long long val1 = (x + k - 1 + k) * x / 2; 
  long long val2 = (k + n - 1 + k) * n / 2 - val1; 
  return std::make_pair(val1, val2); 
}
int main () {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    long long lo = 1, hi = n;
    long long x = -1; 
    while (lo <= hi) {
      long long mid = (lo + hi) / 2; 
      std::pair <long long, long long> pr = f(mid); 
      if (pr.second >= pr.first) {
        x = mid; 
        lo = mid + 1; 
      }
      else {
        hi = mid - 1; 
      }
    }   
    std::pair <long long, long long> pr1 = f(x);
    std::pair <long long, long long> pr2 = f(x + 1);
    std::cout << std::min(std::abs(pr1.first - pr1.second), std::abs(pr2.first - pr2.second)) << std::endl; 
  }
  return 0; 
}