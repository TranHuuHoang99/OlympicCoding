#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <math.h>
int n, R, numQueries;
int timeDfs = 0;  
int f[505][25005]; 
int id[25005]; 
std::vector <int> adj[200005]; 
int home[200005]; 
int cnt[25005]; 
int numb[25005];
int l[200005], r[200005]; 
std::vector <int> listTime[25005];  
std::vector <std::pair <int, int>> save;
std::vector <int> heavy, light;
std::vector <int> listVertex[25005];  
void dfs(int u, int father) {
  for (int i = 0; i < (int) heavy.size(); i++) {
    f[id[heavy[i]]][id[home[u]]] += numb[heavy[i]];  
  }
  numb[home[u]]++; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs(v, u); 
  }                            
  numb[home[u]]--; 
}
void euler_tour(int u, int father) {
  timeDfs++;
  l[u] = timeDfs;
  listTime[home[u]].push_back(l[u]); 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    euler_tour(v, u); 
  }  
  r[u] = timeDfs; 
}
int main() {            
  std::cin >> n >> R >> numQueries; 
  std::cin >> home[1]; 
  for (int i = 2; i <= n; i++) {
    int parent;                        
    std::cin >> parent >> home[i];
    adj[parent].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cnt[home[i]]++;  
    listVertex[home[i]].push_back(i); 
  }
  for (int i = 1; i <= R; i++) {
    save.push_back(std::make_pair(cnt[i], i)); 
  }
  std::sort(save.begin(), save.end());
  std::reverse(save.begin(), save.end()); 
  const int block = 450;
  for (int i = 1; i <= R; i++) {
    id[i] = -1; 
  }
  for (int i = 0; i < (int) save.size(); i++) {
    if (id[save[i].second] != -1) {
      continue;
    }
    id[save[i].second] = i;
    if (save[i].first >= block) {
      heavy.push_back(save[i].second); 
    }
    else {
      light.push_back(save[i].second); 
    }  
  }
  dfs(1, -1);
  timeDfs = 0;
  euler_tour(1, -1);
  for (int query = 1; query <= numQueries; query++) {
    int r1, r2;
    std::cin >> r1 >> r2;  
    if (cnt[r1] >= block) {
      std::cout << f[id[r1]][id[r2]] << std::endl;          
    }
    else {
      std::vector <int> &vec = listVertex[r1]; 
      std::vector <int> &vTime = listTime[r2];
      int ans = 0; 
      for (int i = 0; i < (int) vec.size(); i++) {
        int u = vec[i]; 
        std::vector <int>::iterator it1 = std::lower_bound(vTime.begin(), vTime.end(), l[u]); 
        std::vector <int>::iterator it2 = std::upper_bound(vTime.begin(), vTime.end(), r[u]);
        ans += it2 - it1;
      }
      std::cout << ans << std::endl; 
    }
    fflush(stdout); 
  }            
  return 0;
}