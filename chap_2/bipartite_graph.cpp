#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const int MAX_V = 100005;
vector<int> G[MAX_V];
int V;
int color[MAX_V];

bool dfs(int V, int c) {
  color[V] = c;
  rep(i, G[V].size()) {
    if (color[G[V][i]] == c)
      return false;
    if (color[G[V][i]] == 0 && !dfs(G[V][i], -c))
      return false;
  }
  return true;
}

int main() {
  cin >> V;
  rep(i, V) {
    if (color[i] == 0) {
      if (!dfs(i, 1)) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
