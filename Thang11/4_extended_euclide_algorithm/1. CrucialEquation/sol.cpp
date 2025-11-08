#include <iostream>
#include <algorithm> 

int main () {
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case " << testCase << ": "; 
    int a, b, c; 
    std::cin >> a >> b >> c; 
    int g = std::__gcd(a, b); 
    if (c % g != 0) {
      std::cout << "No";
    }
    else {
      std::cout << "Yes";
    }
    std::cout << std::endl;
  }
  return 0; 
}