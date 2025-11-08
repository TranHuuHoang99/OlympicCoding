#include <iostream>
#include <algorithm>         
#include <math.h>
#include <vector>
#include <iomanip>
#include <utility>
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
struct line {
  double a, b, c; 
  void init(const vecto &nAB, const point &P) {
    a = nAB.x;
    b = nAB.y;
    if (a == 0) {
      b = 1; 
    }
    else if (b == 0) {
      a = 1; 
    }
    c = -(a * P.x + b * P.y);                          
  }
  std::pair <double, double> intersect(const line &other) {
    double x, y; 
    y = (other.c * a - c * other.a) / (b * other.a - other.b * a); 
    x = (-c - b * y) / a; 
    return std::make_pair(x, y); 
  }
};

vecto operator + (const vecto &A, const vecto &B) {
  return (vecto) {A.x + B.x, A.y + B.y};  
}
vecto operator - (const vecto &A, const vecto &B) {
  return (vecto) {B.x - A.x, B.y - A.y};
}
std::vector <point> a;
int n;
double area = 0.0;  

int main () {
  std::cin >> n;
  a.resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].x >> a[i].y; 
  }
  for (int i = 0; i < n; i++) {
    area += a[i].x * a[(i + 1) % n].y - a[i].y * a[(i + 1) % n].x;
  }
  area /= 2.0; 
  area = std::abs(area); 
  std::cout << std::fixed << std::setprecision(12) << area; 
  return 0; 
}