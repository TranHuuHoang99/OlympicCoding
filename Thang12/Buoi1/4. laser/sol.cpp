#include <iostream> 
#include <math.h> 
#include <vector>
#include <algorithm>
#include <map>
const int lim = 1000000000; 
const long long inf = 5000000000000000007LL; 
long long ans[100005];
long long basex[100005], basey[100005], baseqx[100005], baseqy[100005]; 
int n, numQueries;
long long A, B;                  
struct point {
  int x, y;
  int basex, basey; 
  long long c; 
  long long cost;   
};
std::vector <point> a;
struct question {
  int x, y, id;
  int basex, basey; 
  long long cost; 
}; 
std::vector <question> list_questions;
bool compare_point(const point &a, const point &b) {
  return a.x < b.x; 
} 
bool compare_question(const question &a, const question &b) {
  return a.x < b.x; 
}
void update(int index, int L, int R, int position, long long value, std::vector <long long> &it) {
  if (L > position || R < position) {
    return; 
  }
  if (L == R) {
    it[index] = std::min(it[index], value); 
    return; 
  }
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, position, value, it); 
  update(2 * index + 1, mid + 1, R, position, value, it); 
  it[index] = std::min(it[2 * index], it[2 * index + 1]); 
}
long long get(int index, int L, int R, int l, int r, const std::vector <long long> &it) {
  if (l > R || L > r) {
    return inf; 
  }
  if (l <= L && R <= r) {
    return it[index]; 
  }
  int mid = (L + R) / 2;
  long long getLeft = get(2 * index, L, mid, l, r, it);
  long long getRight = get(2 * index + 1, mid + 1, R, l, r, it);
  return std::min(getLeft, getRight);  
}
void solve(std::vector <point> &a, std::vector <question> &list_questions) {                                  
  std::sort(a.begin(), a.end(), compare_point); 
  std::sort(list_questions.begin(), list_questions.end(), compare_question);
  std::vector <int> save; 
  for (int i = 0; i < n; i++) {
    save.push_back(a[i].y); 
  }
  for (int i = 0; i < numQueries; i++) {
    save.push_back(list_questions[i].y); 
  }
  std::map <int, int> ID; 
  std::sort(save.begin(), save.end()); 
  ID[save[0]] = 0; 
  for (int i = 1; i < (int) save.size(); i++) {
    if (save[i] != save[i - 1]) {
      int sz = (int) ID.size(); 
      ID[save[i]] = sz; 
    }
  }
  int sz = (int) ID.size(); 
  std::vector <long long> it(4 * sz + 2, inf); 
  int p = 0; 
  for (int i = 0; i < numQueries; i++) {
    while (p < n && a[p].x <= list_questions[i].x) {
      int y = ID[a[p].y]; 
      update(1, 0, sz - 1, y, a[p].cost, it);
      p++;  
    }  
    int y = ID[list_questions[i].y];
    int id = list_questions[i].id;
    long long minValue = get(1, 0, sz - 1, 0, y, it);
    if (minValue == inf) {
      continue; 
    }
    ans[id] = std::min(ans[id], minValue + list_questions[i].cost);  
  } 
}
int main() {
  std::ios_base::sync_with_stdio(false); 
  std::cin >> n >> numQueries >> A >> B;
  for (int i = 0; i < numQueries; i++) {
    ans[i] = inf; 
  }
  a.resize(n);  
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].x >> a[i].y >> a[i].c;
    a[i].cost = -A * a[i].x - B * a[i].y + a[i].c;   
    a[i].basex = a[i].x; 
    a[i].basey = a[i].y; 
  }
  list_questions.resize(numQueries); 
  for (int i = 0; i < numQueries; i++) {
    std::cin >> list_questions[i].x >> list_questions[i].y; 
    list_questions[i].basex = list_questions[i].x; 
    list_questions[i].basey = list_questions[i].y; 
    list_questions[i].id = i; 
    list_questions[i].cost = A * list_questions[i].x + B * list_questions[i].y;
  }
  solve(a, list_questions);
  for (int i = 0; i < n; i++) {
    a[i].y = lim - a[i].y; 
    a[i].cost = -A * a[i].basex + B * a[i].basey + a[i].c; 
  }
  for (int i = 0; i < numQueries; i++) {
    list_questions[i].y = lim - list_questions[i].y;
    list_questions[i].cost = A * list_questions[i].basex - B * list_questions[i].basey;  
  } 
  solve(a, list_questions); 
  for (int i = 0; i < n; i++) {
    a[i].x = lim - a[i].x;
    a[i].cost = A * a[i].basex + B * a[i].basey + a[i].c;  
  }
  for (int i = 0; i < numQueries; i++) {
    list_questions[i].x = lim - list_questions[i].x; 
    list_questions[i].cost = -A * list_questions[i].basex - B * list_questions[i].basey; 
  }
  solve(a, list_questions);
  for (int i = 0; i < n; i++) {
    a[i].y = lim - a[i].y; 
    a[i].cost = A * a[i].basex - B * a[i].basey + a[i].c; 
  }
  for (int i = 0; i < numQueries; i++) {
    list_questions[i].y = lim - list_questions[i].y; 
    list_questions[i].cost = -A * list_questions[i].basex + B * list_questions[i].basey;
  }
  solve(a, list_questions);
  for (int i = 0; i < numQueries; i++) {
    std::cout << ans[i] << std::endl;
  } 
  return 0; 
}