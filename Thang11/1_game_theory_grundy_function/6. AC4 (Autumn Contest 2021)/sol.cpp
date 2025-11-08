#include <iostream>
#include <vector>
#include <algorithm>
int numTest;
int n;
int a[5][5];
int sumRow[5][5], sumCol[5][5];
int sg[5][5];

int calc(int x, int y) {
  if (x == 0 || y == 0) {
    return 0;
  }
  if (sg[x][y] != -1) {
    return sg[x][y];
  }
  bool found = false;
  std::vector <int> save;
  if (sumRow[x][y] % 2 == 0) {
    found = true;
    save.push_back(calc(x - 1, y));
  }
  if (sumCol[x][y] % 2 == 0) {
    found = true;
    save.push_back(calc(x, y - 1));
  }
  if (found == false) {
    return sg[x][y] = 0;
  }
  std::sort(save.begin(), save.end());
  for (int i = 0; i < (int) save.size(); i++) {
    if (save[i] != i) {
      return sg[x][y] = i;
    }
  }
  return (int) save.size();
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    int grundy = 0;
    for (int i = 1; i <= n; i++) {
      for (int x = 1; x <= 4; x++) {
        for (int y = 1; y <= 4; y++) {
          std::cin >> a[x][y];
          a[x][y] %= 2;
        }
      }
      for (int x = 1; x <= 4; x++) {
        for (int y = 1; y <= 4; y++) {
          sg[x][y] = -1;
        }
      }
      for (int x = 1; x <= 4; x++) {
        for (int y = 1; y <= 4; y++) {
          sumRow[x][y] = (sumRow[x][y - 1] + a[x][y]) % 2;
        }
      }
      for (int y = 1; y <= 4; y++) {
        for (int x = 1; x <= 4; x++) {
          sumCol[x][y] = (sumCol[x - 1][y] + a[x][y]) % 2;
        }
      }
      int value = calc(4, 4);
      grundy ^= value;
    }
    if (grundy == 0) {
      std::cout << "Dau" << std::endl;
    }
    else {
      std::cout << "Bun" << std::endl;
    }
  }
  return 0;
}