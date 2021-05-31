#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10
#define MAX_M 35
#define INF 1000000000
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  while (true) {
    int n, m, p, a, b;
    cin >> n >> m >> p >> a >> b;
    if (n || m || p || a || b == 0)
      break;
    int t[1 << MAX_N];
    for (int i = 1; i < (1 << n); i <<= 1) {
      cin >> t[i];
    }
    int d[MAX_M][MAX_M];
    memset(d, -1, sizeof(d));
    double dp[1 << MAX_N][MAX_M];
    rep(i, 1 << MAX_N) { fill(dp[i], dp[i] + MAX_M, INF); }
    dp[(1 << n) - 1][a] = 0;
    double ans = INF;
    for (int i = (1 << n) - 2; i >= 0; i--) {
      for (int j = 1; j <= m; j++) {
        for (int bit = 1; bit < (1 << n); bit <<= 1) {
          if ((i & bit) != 0)
            continue;
          for (int pre = 1; pre <= m; pre++) {
            if (dp[pre][j] < 0)
              continue;
            dp[i][j] =
                min(dp[i][j], dp[i | bit][pre] + (double)d[pre][j] / t[bit]);
          }
        }
        if (j == b)
          ans = min(ans, dp[i][j]);
      }
    }
    if (ans == INF) {
      cout << "Impossible" << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}
