#include <iostream> 
bool isPrime[1000005]; 
int phi[1000005]; 
int numTest; 

void init() {
  for (int i = 1; i <= 1000000; i++) {
    isPrime[i] = true; 
    phi[i] = i; 
  }
  isPrime[1] = false;
  for (int i = 2; i <= 1000000; i++) {
    if (isPrime[i] == true) {
      phi[i] /= i;
      phi[i] *= i - 1; 
      for (int j = 2 * i; j <= 1000000; j += i) {
        isPrime[j] = false;
        phi[j] /= i;
        phi[j] *= i - 1; 
      }
    }
  }
}

int main () {
  init();
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n;
    std::cout << phi[n] << std::endl;
  }
  return 0; 
}