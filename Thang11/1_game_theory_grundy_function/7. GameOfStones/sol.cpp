#include <iostream>
int grundy[61] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};
int n; 

int main() {
  std::cin >> n;
  int ans = 0; 
  for (int i = 1; i <= n; i++) {
    int x; 
    std::cin >> x;
    ans ^= grundy[x]; 
  }
  std::cout << (ans == 0 ? "YES" : "NO");
  return 0;
}