#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 15;
const int MAX_M = 15;

int dp[2][1 << MAX_M];
int n, m;
long long M;
bool color[MAX_N][MAX_M];
int main() {
  cin >> n >> m >> M;
  int *crt = dp[0];
  int *next = dp[1];
  crt[0] = 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      for (int used = 0; used < 1 << m; used++) {
        if ((used >> j & 1) || color[i][j])
          next[used] = crt[used & ~(1 << j)];
        else {
          int res = 0;
          if (j + 1 < m && !(used >> (j + 1) & 1) && !color[i][j + 1]) {
            res += crt[used | 1 << (j + 1)];
          }
          if (i + 1 < n && !color[i + 1][j]) {
            res += crt[used | 1 << j];
          }
          next[used] = res % M;
        }
      }
      swap(crt, next);
    }
  }
  cout << crt[0] << endl;
  return 0;
}
