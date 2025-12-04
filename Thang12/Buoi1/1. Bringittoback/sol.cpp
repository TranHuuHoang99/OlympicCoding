#include <iostream> 

int main() {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, m;
    std::cin >> n >> m;
    if (n == 2) {
      if (m % 2 == 0) {
        std::cout << "1 2";
      }
      else {
        std::cout << "2 1";
      }
      std::cout << std::endl;
      continue;
    }
    if (m < n) {
      for (int i = n; i >= n - m + 1; i--) {
        std::cout << i << ' '; 
      }
      for (int i = 1; i <= n - m; i++) {
        std::cout << i << ' '; 
      }
      std::cout << std::endl;
      continue; 
    }
    for (int i = n; i >= 1; i--) {
      std::cout << i << ' ';
    }
    std::cout << std::endl; 
  }
  return 0; 
}