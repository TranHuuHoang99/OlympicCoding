#include <iostream> 
#include <math.h>
struct point {
  double x, y; 
  bool operator == (const point &other) const {
    return (x == other.x && y == other.y); 
  }
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

int numTest;
point A, B, C, D;

bool isOnSegment(const point &A, const point &B, const point &C) { // check point C is on a segment AB
  vecto AB(B.x - A.x, B.y - A.y);
  vecto AC(C.x - A.x, C.y - A.y);  
  if (AB.cross(AC) == 0) {
    vecto CA(A.x - C.x, A.y - C.y);
    vecto CB(B.x - C.x, B.y - C.y);
    if (CA.dot(CB) < 0) {
      return true; 
    } 
  }
  return false; 
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

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y; 
    if (A == C || A == D || B == C || B == D) {
      std::cout << "YES" << std::endl;
      continue;
    }
    if (isOnSegment(A, B, C) == true || isOnSegment(A, B, D) == true || isOnSegment(C, D, A) == true || isOnSegment(C, D, B) == true) {
      std::cout << "YES" << std::endl;
      continue; 
    }
    if ((ccw(A, B, C) * ccw(A, B, D) < 0) && (ccw(C, D, A) * ccw(C, D, B) < 0)) {
      std::cout << "YES" << std::endl;
    }   
    else {
      std::cout << "NO" << std::endl;
    }
  }
  return 0; 
}