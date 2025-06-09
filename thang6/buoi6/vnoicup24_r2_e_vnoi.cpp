#include <iostream>
#include <algorithm>
#include <vector> 
#include <math.h>
struct edge {
  int u, v;
  long long weight; 
  bool operator < (const edge &other) {
    return weight < other.weight; 
  }
};
int numTest;
int n, m, k;  
int root[1005];
std::vector <edge> listEdges[10];
std::vector <edge> listImportantEdges[10];
std::vector <std::vector <int> > listStates;
long long s[10];   
int findRoot(int u) {
  return root[u] = (u == root[u] ? u : findRoot(root[u])); 
}
void solve(const int &net) {
  for (int i = 1; i <= n; i++) {
    root[i] = i; 
  }
  std::vector <edge> &e = listEdges[net]; 
  std::sort(e.begin(), e.end()); 
  long long cost = 0LL; 
  for (int i = 0; i < (int) e.size(); i++) {
    int u = e[i].u, v = e[i].v; 
    int rootu = findRoot(u);
    int rootv = findRoot(v); 
    if (rootu != rootv) {
      cost += e[i].weight; 
      listImportantEdges[net].push_back(e[i]); 
      root[rootu] = rootv; 
    }
  }                              
}                        
void backTrack(int pos, std::vector <int> curState) {
  if (pos == k) {
    listStates.push_back(curState); 
    return; 
  }  
  for (int choose = 0; choose <= 1; choose++) {
    std::vector <int> tmp = curState;
    tmp.push_back(choose); 
    backTrack(pos + 1, tmp); 
  }
}
int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m >> k; 
    listStates.clear(); 
    backTrack(0, {}); 
    for (int net = 0; net < k; net++) {
      listEdges[net].clear();
      listImportantEdges[net].clear(); 
    }
    for (int i = 0; i < m; i++) {
      int u, v, net; 
      long long weight; 
      std::cin >> u >> v >> net >> weight;
      net--; 
      listEdges[net].push_back((edge) {u, v, weight});  
    }
    for (int net = 0; net < k; net++) {
      std::cin >> s[net];
    }
    for (int net = 0; net < k; net++) {
      solve(net); 
    }
    long long ans = 1000000000000007LL; 
    for (int j = 0; j < (int) listStates.size(); j++) {
      std::vector <int> state = listStates[j]; 
      std::vector <edge> e;
      long long cost = 0LL;
      for (int net = 0; net < k; net++) {
        if (state[net] == 1) {
          cost += s[net];
          for (int i = 0; i < (int) listImportantEdges[net].size(); i++) {
            e.push_back((edge) {listImportantEdges[net][i].u, listImportantEdges[net][i].v, listImportantEdges[net][i].weight});
          } 
        }
        else {
          for (int i = 0; i < (int) listImportantEdges[net].size(); i++) {
            e.push_back((edge) {listImportantEdges[net][i].u, listImportantEdges[net][i].v, 2LL * listImportantEdges[net][i].weight});
          }
        }
      }
      std::sort(e.begin(), e.end());
      for (int i = 1; i <= n; i++) {
        root[i] = i; 
      }   
      for (int i = 0; i < (int) e.size(); i++) {
        int u = e[i].u, v = e[i].v; 
        int rootu = findRoot(u);
        int rootv = findRoot(v);
        if (rootu != rootv) {
          root[rootu] = rootv; 
          cost += e[i].weight; 
        } 
      }
      ans = std::min(ans, cost); 
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}