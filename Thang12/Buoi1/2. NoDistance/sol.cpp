#include <iostream> 

int main() {
  int n, a, b;
  std::cin >> n >> a >> b;
  int x = n - 2 - a - b;
  if (x >= 0) {
    std::cout << x;
    return 0; 
  }
  std::cout << a + b - n;
  return 0; 
}