#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <utility>
int fenw_n;
std::vector <int> fenw_val, fenw_idx;
void fenw_init(int n) {
  fenw_n = n;
  fenw_val.resize(fenw_n + 2, -1000000007);
  fenw_idx.resize(fenw_n + 2, -1);
}
void fenw_clear() {
  for (int i = 1; i <= fenw_n; i++) {
    fenw_val[i] = -1000000007;
    fenw_idx[i] = -1;
  }
}
void fenw_update(int pos, int v, int id) {
  for (int p = pos; p <= fenw_n; p += p & -p) {
    if (v > fenw_val[p]) {
      fenw_val[p] = v;
      fenw_idx[p] = id;
    }
  }
}
std::pair <int, int> fenw_query(int pos) {
  int bestV = -1000000007;
  int bestI = -1;
  for (int p = pos; p > 0; p -= p & -p) {
    if (fenw_val[p] > bestV) {
      bestV = fenw_val[p];
      bestI = fenw_idx[p];
    }
  }
  return std::make_pair(bestV, bestI);
}
int main() {
  int N;
  std::cin >> N;
  std::vector <int> A(N + 1);
  int minA = 1000000007;
  int maxA = -1000000007;
  for (int i = 1; i <= N; i++) {
    std::cin >> A[i];
    if (A[i] < minA) {
      minA = A[i];
    }
    if (A[i] > maxA) {
      maxA = A[i];
    }
  }
  int R = maxA - minA;
  int Kmax = (int) std::sqrt(1 + 8 * R); 
  const int inf = 1000000007;
  std::vector <int> f_prev(N + 1, 0);
  std::vector <int> f_curr(N + 1, inf);
  std::vector <std::vector <int>> pre(Kmax + 2, std::vector <int>(N + 1, -1));
  for (int i = 1; i <= N; i++) {
    pre[1][i] = -1;
  }
  fenw_init(std::max(1, maxA));
  int bestLen = 1;
  int bestEnd = 1;
  for (int len = 1; len < Kmax; len++) {
    fenw_clear();
    bool anyUpdate = false;
    for (int i = 1; i <= N; i++) {
      std::pair <int, int> got = fenw_query(A[i]);
      int prevVal = got.first;
      int prevIdx = got.second;
      if (prevIdx != -1) {
        f_curr[i] = A[i] - prevVal;
        pre[len + 1][i] = prevIdx;
        anyUpdate = true;
        if (len + 1 > bestLen) {
          bestLen = len + 1;
          bestEnd = i;
        }
      } 
      else {
        f_curr[i] = inf;
        pre[len + 1][i] = -1;
      }
      if (f_prev[i] < inf) {
        long long thr = (long long) A[i] + (long long) f_prev[i] + 1LL;
        if (thr <= (long long) maxA) {
          int pos = thr;
          if (pos >= 1) {
            fenw_update(pos, A[i], i);
          }
        }
      }
    }
    f_prev.swap(f_curr);
    for (int i = 1; i <= N; i++) {
      f_curr[i] = inf;
    }
    if (anyUpdate == false) {
      break;
    }
  }
  std::vector <int> ans;
  int curIdx = bestEnd;
  int curLen = bestLen;
  while (curIdx != -1) {
    ans.push_back(curIdx);
    int prv = pre[curLen][curIdx];
    curIdx = prv;
    curLen--;
    if (curLen == 0) {
      break;
    }
  }
  std::reverse(ans.begin(), ans.end());
  std::cout << (int) ans.size() << std::endl;
  for (int i = 0; i < (int) ans.size(); i++) {
    std::cout << ans[i] << ' ';
  }
  return 0;
}
