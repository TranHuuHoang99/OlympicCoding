#include <iostream> 
#include <math.h>
#include <iomanip>
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

int main () {
  point A, B;
  std::cin >> A.x >> A.y >> B.x >> B.y; 
  vecto OA(A.x, A.y), OB(B.x, B.y); 
  double cosAngle = OA.dot(OB) / (OA.length() * OB.length()); 
  std::cout << std::fixed << std::setprecision(12) << std::acos(cosAngle); 
  return 0; 
}