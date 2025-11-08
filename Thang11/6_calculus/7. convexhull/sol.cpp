#include <iostream>
#include <vector>
#include <algorithm>         
#include <math.h>
struct point {
  long long x, y; 
  bool operator == (const point &other) const {
    return (x == other.x && y == other.y); 
  }
};
struct vecto {
  long long x, y; 
  vecto(long long _x, long long _y) {
    x = _x;
    y = _y;
  }
  long long dot(const vecto &other) {
    return x * other.x + y * other.y; 
  }
  long long cross(const vecto &other) {
    return x * other.y - y * other.x; 
  }
};
int ccw(const point &A, const point &B, const point &C) { // check counter clockwise
  vecto AB(B.x - A.x, B.y - A.y);
  vecto AC(C.x - A.x, C.y - A.y); 
  if (AB.cross(AC) < 0) {
    return 1; 
  }
  else if (AB.cross(AC) > 0) {
    return -1; 
  }
  return 0; 
}
        
int n;
std::vector <point> p;
std::vector <point> hull; 

bool compare(const point &A, const point &B) {
  if (A.x != B.x) {
    return (A.x < B.x); 
  } 
  return (A.y < B.y); 
}

int main () {
  std::cin >> n;
  p.resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> p[i].x >> p[i].y; 
  }                     
  std::sort(p.begin(), p.end(), compare);
  hull.push_back(p[0]); 
  for (int i = 1; i < n; i++) {
    while ((int) hull.size() >= 2 && ccw(hull[(int) hull.size() - 2], hull.back(), p[i]) < 0) {
      hull.pop_back();  
    }
    hull.push_back(p[i]); 
  }
  for (int i = n - 2; i >= 0; i--) {
    while ((int) hull.size() >= 2 && ccw(hull[(int) hull.size() - 2], hull.back(), p[i]) < 0) {
      hull.pop_back(); 
    }
    hull.push_back(p[i]); 
  }
  if (n > 1) {
    hull.pop_back(); 
  }
  std::cout << (int) hull.size() << std::endl;
  for (int i = 0; i < (int) hull.size(); i++) {
    std::cout << hull[i].x << ' ' << hull[i].y << std::endl;
  }
  return 0;
}