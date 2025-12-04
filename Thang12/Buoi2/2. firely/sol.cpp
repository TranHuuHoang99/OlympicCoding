#include <iostream>
int n, numQueries; 
long long a[200005]; 
long long sum[400005]; 
int main() {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> numQueries;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
      sum[i] = sum[i - 1] + a[i];
    }
    for (int i = n + 1; i <= 2 * n; i++) {
      sum[i] = sum[i - 1] + a[i - n]; 
    }
    for (int query = 1; query <= numQueries; query++) {
      long long l, r;
      std::cin >> l >> r;
      l--;
      r--; 
      long long i = l / n, j = r / n; 
      l %= n;
      r %= n;
      std::cout << (long long) (j - i + 1) * sum[n] - (sum[i + l] - sum[i]) - (sum[j + n] - sum[j + r + 1]) << std::endl;
    }
  }
  return 0; 
}