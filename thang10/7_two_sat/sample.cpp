#include <iostream> 
#include <vector> 
#include <math.h>
#include <stack>
#include <utility> 
#include <set> 
const int SHIFT = 100; 
int numbCities, numbEdges;
std::vector <int> adj[2 * SHIFT + 5];
int root[2 * SHIFT + 5];
std::vector <int> listVertex[2 * SHIFT + 5];
int dfsCount = 0;
int low[2 * SHIFT + 5], numb[2 * SHIFT + 5];  
bool deleted[2 * SHIFT + 5]; 
std::stack <int> store; 
int groupVertex = 0; 
std::vector <int> adjGroup[2 * SHIFT + 5]; 
std::set <std::pair <int, int> > haveEdge; 
int state[2 * SHIFT + 5]; 
int stateGroup[2 * SHIFT + 5]; 
std::vector <int> topo;
bool visited[2 * SHIFT + 5];  

void dfs(int u) {
  dfsCount++; 
  numb[u] = low[u] = dfsCount;
  store.push(u);
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (deleted[v] == true) {
      continue; 
    }
    if (numb[v] == 0) {
      dfs(v); 
      low[u] = std::min(low[u], low[v]); 
    }
    else {
      low[u] = std::min(low[u], numb[v]); 
    }
  } 
  if (low[u] == numb[u]) {
    groupVertex++; 
    do {
      int v = store.top(); 
      store.pop(); 
      listVertex[groupVertex].push_back(v); 
      root[v] = groupVertex; 
      deleted[v] = true; 
      if (u == v) {
        break; 
      }
    }
    while (true); 
  }
}

void dfsTopo(int u) {
  visited[u] = true; 
  for (int i = 0; i < (int) adjGroup[u].size(); i++) {
    int v = adjGroup[u][i]; 
    if (visited[v] == false) {
      dfsTopo(v); 
    }
  }
  topo.push_back(u); 
}

void dfsGroup(int group, int currentState) {
  stateGroup[group] = currentState;
  for (int i = 0; i < (int) listVertex[group].size(); i++) {
    int u = listVertex[group][i]; 
    state[u] = currentState; 
    int v = 2 * SHIFT - u; 
    int rootv = root[v]; 
    if (stateGroup[rootv] == currentState) {
      std::cout << "Impossible";
      exit(0);
    }
    if (stateGroup[rootv] == 0) {
      dfsGroup(rootv, 3 - currentState); 
    }
  }
}

int main () {
  std::cin >> numbCities >> numbEdges; 
  for (int edge = 1; edge <= numbEdges; edge++) {
    int u, v, need;
    std::cin >> u >> v >> need;             
    if (need == 1) {
      adj[SHIFT + u].push_back(SHIFT + v);
      adj[SHIFT + v].push_back(SHIFT + u);
      adj[SHIFT - u].push_back(SHIFT - v); 
      adj[SHIFT - v].push_back(SHIFT - u);   
    } 
    else {
      adj[SHIFT + u].push_back(SHIFT - v);
      adj[SHIFT + v].push_back(SHIFT - u);
      adj[SHIFT - u].push_back(SHIFT + v);
      adj[SHIFT - v].push_back(SHIFT + u); 
    }
  }
  for (int u = SHIFT - numbCities; u <= SHIFT + numbCities; u++) {
    if (u == SHIFT) {
      continue; 
    }
    if (numb[u] == 0) {
      dfs(u); 
    }
  }
  for (int i = 1; i <= numbCities; i++) {
    if (root[SHIFT - i] == root[SHIFT + i]) {
      std::cout << "Impossible"; 
      return 0; 
    }
  }
  for (int u = SHIFT - numbCities; u <= SHIFT + numbCities; u++) {
    for (int i = 0; i < (int) adj[u].size(); i++) {
      int v = adj[u][i];
      int rootu = root[u];
      int rootv = root[v];
      if (rootu != rootv && haveEdge.find(std::make_pair(rootu, rootv)) == haveEdge.end()) {
        adjGroup[rootu].push_back(rootv);
        haveEdge.insert(std::make_pair(rootu, rootv));   
      }  
    }
  }
  for (int i = 1; i <= groupVertex; i++) {
    if (visited[i] == false) {
      dfsTopo(i); 
    }
  }
  for (int i = 0; i < (int) topo.size(); i++) {
    int group = topo[i];
    if (stateGroup[group] == 0) {
      dfsGroup(group, 1); 
    }  
  }
  std::vector <int> ans; 
  for (int i = 1; i <= numbCities; i++) {
    if (state[SHIFT + i] == 1) {
      ans.push_back(i); 
    }
  }
  std::cout << (int) ans.size() << std::endl; 
  for (int i = 0; i < (int) ans.size(); i++) {
    std::cout << ans[i] << ' '; 
  }
  return 0; 
}             