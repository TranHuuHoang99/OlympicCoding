#include <iostream> 
#include <vector> 
bool isPrime[1000005]; 
long long phi[1000005]; 
long long f[1000005]; 
long long sum[1000005];
int numTest; 

void init() {
  for (int i = 1; i <= 1000000; i++) {
    phi[i] = i; 
  }
  for (int i = 2; i <= 1000000; i++) {
    isPrime[i] = true; 
  }
  for (int i = 2; i <= 1000000; i++) {
    if (isPrime[i] == true) {
      phi[i] *= i - 1;
      phi[i] /= i;
      for (int j = 2 * i; j <= 1000000; j += i) {
        phi[j] *= i - 1;
        phi[j] /= i; 
        isPrime[j] = false; 
      }   
    }
  }
  sum[0] = 0; 
  for (int i = 1; i <= 1000000; i++) {
    for (int j = 2 * i; j <= 1000000; j += i) {
      sum[j] += (long long) i * phi[j / i]; 
    }
  }
  for (int i = 1; i <= 1000000; i++) {
    sum[i] += sum[i - 1];
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  init(); 
  while (true) {
    int n;
    std::cin >> n; 
    if (n == 0) {
      break; 
    }
    std::cout << sum[n] << std::endl; 
  }
  return 0;  
}