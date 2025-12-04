#include <iostream>
int numTest, N;
int main() {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
      std::cout << i << ' ' << 1 << std::endl;
    }
  }
  return 0;
}