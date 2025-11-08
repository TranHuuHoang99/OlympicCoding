#include <iostream>
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
struct line {
  long long a, b, c; 
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
};

vecto operator + (const vecto &A, const vecto &B) {
  return (vecto) {A.x + B.x, A.y + B.y};  
}
vecto operator - (const vecto &A, const vecto &B) {
  return (vecto) {B.x - A.x, B.y - A.y};
}
point A, B; 

int main () {
  std::cin >> A.x >> A.y >> B.x >> B.y;
  vecto AB(B.x - A.x, B.y - A.y);
  vecto nAB(-AB.y, AB.x);
  line l;
  l.init(nAB, A);    
  std::cout << l.a << ' ' << l.b << ' ' << l.c;
  return 0; 
}