#include <iostream> 
int numTest;

int grundy(int x) {
  if (x == 1) {
    return 1; 
  }
  if (x == 2) {
    return 0; 
  }
  if (x % 2 == 1) {
    return 1; 
  }
  return 2; 
}            

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n;
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
      int m, k;
      std::cin >> m >> k; 
      ans ^= grundy(m); 
    }
    std::cout << (ans == 0 ? "BEN" : "BOB") << std::endl; 
  }
  return 0; 
}