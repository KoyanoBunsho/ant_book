#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

const int MAX_N = 505;
int W, H, N;
int X1[MAX_N], X2[MAX_N], Y1[MAX_N], Y2[MAX_N];
bool fld[MAX_N * 6][MAX_N * 6];
int compress(int *x1, int *x2, int w) {
  vector<int> xs;
  rep(i, N) {
    for (int d = -1; d <= 1; d++) {
      int tx1 = x1[i] + d, tx2 = x2[i] + d;
      if (1 <= tx1 && tx1 <= W)
        xs.push_back(tx1);
      if (1 <= tx2 && tx2 <= W)
        xs.push_back(tx2);
    }
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  rep(i, N) {
    x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
    x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
  }
  return xs.size();
}

int main() {
  W = compress(X1, X2, W);
  H = compress(Y1, Y2, H);
  memset(fld, 0, sizeof(fld));
  rep(i, N) {
    for (int y = Y1[i]; y <= Y2[i]; y++) {
      for (int x = X1[i]; x <= X2[i]; x++) {
        fld[y][x] = true;
      }
    }
  }
  int ans = 0;
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, -1, 0, 1};
  rep(y, H) {
    rep(x, W) {
      if (fld[y][x])
        continue;
      ans++;
      queue<pair<int, int>> que;
      que.push(make_pair(x, y));
      while (!que.empty()) {
        int sx = que.front().first, sy = que.front().second;
        que.pop();
        rep(i, 4) {
          int tx = sx + dx[i], ty = sy + dy[i];
          if (tx < 0 || W <= tx || ty < 0 || H <= ty)
            continue;
          if (fld[ty][tx])
            continue;
          que.push(make_pair(tx, ty));
          fld[ty][tx] = true;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
