#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int N;
  cin >> N;
  vector<int> H(N), W(N);
  rep(i, N) cin >> H[i] >> W[i];
  vector<string> sfi(4);
  vector<vector<int>> fi(4, vector<int>(4));
  rep(i, 4) {
    cin >> sfi[i];
    rep(j, 4) {
      if (sfi[i][j] == 'R')
        fi[i][j] = 0;
      else if (sfi[i][j] == 'G')
        fi[i][j] = 1;
      else
        fi[i][j] = 2;
    }
  }
  vector<int> dp(1 << 16, -1);
  queue<int> que;
  dp[0] = 0;
  que.push(0);
  while (!que.empty()) {
    int cur = que.front();
    que.pop();
    rep(i, N) {
      for (int sx = -H[i] + 1; sx < 4; ++sx) {
        for (int sy = -W[i] + 1; sy < 4; ++sy) {
          rep(c, 3) {
            int ncur = cur;
            for (int x = max(sx, 0); x < min(sx + H[i], 4); x++) {
              for (int y = max(sx, 0); y < min(sy + W[i], 4); y++) {
                if (fi[x][y] == c)
                  ncur |= 1 << (x * 4 + y);
                else
                  ncur &= ~(1 << (x * 4 + y));
              }
            }
            if (dp[ncur] == -1) {
              dp[ncur] = dp[cur] + 1;
              que.push(ncur);
            }
          }
        }
      }
    }
  }
  cout << dp[(1 << 16) - 1] << endl;
}
