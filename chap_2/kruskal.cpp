#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

const int MAX_N = 100005;
const int MAX_E = 100005;
int par[MAX_N];
int rank_a[MAX_N];
struct edge {
  int from, to, cost;
};
bool comp(const edge &e1, const edge &e2) { return e1.cost < e2.cost; }
edge es[MAX_E];
int V, E;

void init(int n) {
  rep(i, n) {
    par[i] = i;
    rank_a[i] = 0;
  }
}

int find(int x) {
  if (par[x] == x)
    return x;
  else {
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;
  if (rank_a[x] > rank_a[y]) {
    par[y] = x;
  } else {
    par[x] = y;
    if (par[x] == par[y])
      rank_a[y]++;
  }
}
bool same(int x, int y) { return find(x) == find(y); }
int kruskal() {
  init(V);
  sort(es, es + E, comp);
  int res = 0;
  rep(i, E) {
    edge e = es[i];
    if (!same(e.from, e.to)) {
      res += e.cost;
      unite(e.from, e.to);
    }
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, r;
    cin >> n >> m >> r;
    V = n + m;
    E = r;
    rep(i, r) {
      int x, y, d;
      cin >> x >> y >> d;
      es[i] = (edge){x, y + n, -d};
    }
    cout << V * 10000 + kruskal() << endl;
  }
  return 0;
}
