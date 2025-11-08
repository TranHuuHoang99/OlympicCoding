#include <iostream> 
#include <math.h>
struct point {
  double x, y; 
};
struct vecto {
  double x, y; 
  vecto(double _x, double _y) {
    x = _x;
    y = _y;
  }
  double dot(const vecto &other) {
    return x * other.x + y * other.y; 
  }
  double cross(const vecto &other) {
    return x * other.y - y * other.x; 
  }
  double length() {
    return std::sqrt(x * x + y * y); 
  }
};

vecto operator + (const vecto &A, const vecto &B) {
  return (vecto) {A.x + B.x, A.y + B.y};  
}
vecto operator - (const vecto &A, const vecto &B) {
  return (vecto) {B.x - A.x, B.y - A.y};
}
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

int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    point A, B, C;
    std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y; 
    if (ccw(A, B, C) == 1) {
      std::cout << "RIGHT" << std::endl;
    }
    else if (ccw(A, B, C) == -1) {
      std::cout << "LEFT" << std::endl;
    }
    else {
      std::cout << "TOUCH" << std::endl;
    }
  }
  return 0;
}