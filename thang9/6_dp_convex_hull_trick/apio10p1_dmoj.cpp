#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
struct line {
  long long a, b, denox, numex; 
};
std::vector <line> hull; 
long long f[1000005]; 
int n; 
long long sum[1000005];
long long a, b, c; 
std::pair <long long, long long> intersectx(const line &l1, const line &l2) {
  long long deno = l2.b - l1.b; 
  long long nume = l1.a - l2.a; 
  if (nume < 0) {
    deno = -deno;
    nume = -nume; 
  }
  return std::make_pair(deno, nume); 
}
long long query(const long long &x) {
  int lo = 0; 
  int hi = (int) hull.size() - 1; 
  int p = -1; 
  while (lo <= hi) {
    int mid = (lo + hi) / 2; 
    if (hull[mid].denox <= x * hull[mid].numex) {
      p = mid; 
      lo = mid + 1; 
    }
    else {
      hi = mid - 1; 
    }
  }                                      
  return hull[p].a * x + hull[p].b; 
}
bool bad(const line &l1, const line &l2, const line &l3) {
  std::pair <long long, long long> x12 = intersectx(l1, l2); 
  std::pair <long long, long long> x13 = intersectx(l1, l3);
  if (x13.first * x12.second < x12.first * x13.second) {
    return true; 
  } 
  return false;
} 

int main () {
  std::cin >> n >> a >> b >> c;
  for (int i = 1; i <= n; i++) {
    long long soldier; 
    std::cin >> soldier; 
    sum[i] = sum[i - 1] + soldier; 
  } 
  f[1] = a * sum[1] * sum[1] + b * sum[1] + c;
  hull.push_back((line) {-2LL * a * sum[1], f[1] - b * sum[1] + a * sum[1] * sum[1], -1, 1}); 
  for (int i = 2; i <= n; i++) {
    long long x = sum[i];
    f[i] = 0; 
    long long ymax = query(x); 
    if (ymax > 0) {
      f[i] = ymax; 
    }
    f[i] += a * sum[i] * sum[i] + b * sum[i] + c; 
    line l = (line) {-2LL * a * sum[i], f[i] - b * sum[i] + a * sum[i] * sum[i], -1, 1};
    while ((int) hull.size() >= 2 && bad(hull[(int) hull.size() - 2], hull.back(), l) == true) {
      hull.pop_back(); 
    } 
    std::pair <long long, long long> xx = intersectx(hull.back(), l); 
    l.denox = xx.first;
    l.numex = xx.second;
    hull.push_back(l); 
  }
  std::cout << f[n]; 
  return 0; 
}