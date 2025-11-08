#include <iostream>
#include <math.h> 
int main() {
  int numTest; 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int res = 0;
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      std::cin >> x;
      res ^= x; 
    }
    std::cout << (res > 0 ? "first" : "second") << std::endl;
  }
  return 0;
}