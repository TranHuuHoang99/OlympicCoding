#include <iostream>
int numTest; 
 
int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      std::cin >> x;
      ans ^= x % 4; 
    }
    std::cout << (ans > 0 ? "first" : "second") << std::endl;
  }
  return 0; 
}