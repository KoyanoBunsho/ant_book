#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int n;
const int MAX_N = 20;
int d[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N];
const int INF = 1000000007;

int rec(int S, int v) {
  if (dp[S][v] >= 0) {
    return dp[S][v];
  }
  if (S == (1 << n) - 1 && v == 0) {
    return dp[S][v] = 0;
  }
  int res = INF;
  rep(u, n) {
    if (!(S >> u & 1)) {
      res = min(res, rec(S | 1 << u, u) + d[v][u]);
    }
  }
  return dp[S][v] = res;
}

int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n;
  cout << rec(0, 2) << endl;
  return 0;
}
