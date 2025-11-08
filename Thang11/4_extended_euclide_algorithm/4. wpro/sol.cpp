#include <iostream>
#include <math.h>
#include <algorithm>
const unsigned long long inf = 4000000000000000007ULL;
unsigned long long f[10005];
unsigned long long a[10005];
int n;
long long C;
long long D;
long long L1;
long long L2;
long long gcd;
long long xg;
long long yg;
unsigned long long sum[10005];
void extendedEuclide(const long long &a, const long long &b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  long long x1;
  long long y1;
  extendedEuclide(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
}
__int128 ceil_div(__int128 a, __int128 b) {
  if (b < 0) {
    a = -a;
    b = -b;
  }
  if (a >= 0) {
    return (a + b - 1) / b;
  }
  return a / b;
}
__int128 floor_div(__int128 a, __int128 b) {
  if (b < 0) {
    a = -a;
    b = -b;
  }
  if (a >= 0) {
    return a / b;
  }
  return (a - b + 1) / b;
}
long long g(const long long &len) {
  if (len % gcd != 0) {
    return -1;
  }
  __int128 x = (__int128) xg * (len / gcd);
  __int128 y = (__int128) yg * (len / gcd);
  long long l1 = L1 / gcd;
  long long l2 = L2 / gcd;
  __int128 l = ceil_div(-x, l2);
  __int128 r = floor_div(y, l1);
  if (l > r) {
    return -1;
  }
  __int128 k = r;
  __int128 res = x + y + k * (__int128)(l2 - l1);
  if (res < 0 || res > inf) {
    return -1;
  }
  return (long long) res;
}
int main() {
  freopen("wpro.inp", "r", stdin);
  freopen("wpro.out", "w", stdout);
  std::cin >> n >> L1 >> L2 >> C >> D;
  if (L1 < L2) {
    std::swap(L1, L2);
  }
  gcd = std::__gcd(L1, L2);
  extendedEuclide(L1, L2, xg, yg);
  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    f[i] = inf;
  }
  f[0] = 0;
  for (int i = 0; i < n; i++) {
    if (f[i] != inf) {
      for (int j = i + 1; j <= n; j++) {
        long long totalWoods = sum[j] - sum[i];
        long long cost = g(totalWoods);
        if (cost == -1) {
          continue;
        }
        unsigned long long newVal = f[i] + D * (j - i - 1) + C * (cost - 1);
        if (newVal < f[j]) {
          f[j] = newVal;
        }
      }
    }
  }
  std::cout << f[n];
  return 0;
}