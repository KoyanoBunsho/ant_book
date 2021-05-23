#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

const int MAX_E = 100005;
const int MAX_V = 100005;
const int INF = 1000000007;
struct edge {
  int from, to, cost;
};

edge es[MAX_E];
int d[MAX_V];
int V, E;

void shortest_path(int s) {
  rep(i, V) d[i] = INF;
  d[s] = 0;
  while (true) {
    bool update = false;
    rep(i, E) {
      edge e = es[i];
      if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        update = true;
      }
    }
    if (!update)
      break;
  }
}

bool find_negative_loop() {
  memset(d, 0, sizeof(d));
  rep(i, V) {
    rep(j, E) {
      edge e = es[j];
      if (d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        if (i == V - 1) {
          cout << "negative loop" << endl;
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  cin >> V >> E;
  rep(i, E) cin >> es[i].from >> es[i].to >> es[i].cost;
  int s;
  cin >> s;
  shortest_path(s);
  rep(i, V) { printf("%d\n", d[i]); }
  if (find_negative_loop())
    cout << "Has negative loop" << endl;
  else
    cout << "No negative loop" << endl;
  return 0;
}
