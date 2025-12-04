#include <iostream>
#include <queue>
int key[102]; 
int dist[100005]; 

int main () {
  int numTest; 
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, k; 
    std::cin >> n >> k; 
    for (int i = 1; i <= n; i++) {
      std::cin >> key[i]; 
    }
    for (int i = 0; i < 100000; i++) {
      dist[i] = -1; 
    }
    dist[1] = 0; 
    std::queue <int> myqueue; 
    myqueue.push(1); 
    while (myqueue.empty() == false) {
      int u = myqueue.front();
      myqueue.pop(); 
      for (int i = 1; i <= n; i++) {
        int v = u * key[i]; 
        if (v > 100000 || dist[v] != -1) {
          continue; 
        }
        dist[v] = dist[u] + 1; 
        myqueue.push(v); 
      }
    }
    if (dist[k] == -1) {
      std::cout << "Impossible"; 
    }
    else {
      std::cout << dist[k];
    }
    std::cout << std::endl; 
  }
  return 0; 
}