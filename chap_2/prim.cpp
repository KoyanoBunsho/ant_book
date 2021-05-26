#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

template <typename T> struct edge {
  int from, to;
  T cost;
  edge(int to, T cost) : from(-1), to(to), cost(cost) {}
  edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
  bool operator<(edge x) { return this->cost < x.cost; }
};

template <typename T> using Edges = vector<edge<T>>;
template <typename T> using WeightedGraph = vector<Edges<T>>;
template <typename T> using Matrix = vector<vector<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T> T prim(WeightedGraph<T> &g) {
  using Pi = pair<T, int>;
  T total = 0;
  vector<bool> used(g.size(), false);
  priority_queue<Pi, vector<Pi>, greater<Pi>> que;
  que.emplace(0, 0);
  while (!que.empty()) {
    auto p = que.top();
    que.pop();
    if (used[p.second])
      continue;
    used[p.second] = true;
    total += p.first;
    for (auto &e : g[p.second]) {
      que.emplace(e.cost, e.to);
    }
  }
  return total;
}

int main() {
  int n, m;
  cin >> n >> m;
  WeightedGraph<ll> g(n);
  rep(i, m) {
    int s, t, c;
    cin >> s >> t >> c;
    g[s].push_back(edge<ll>{t, c});
    g[t].push_back(edge<ll>{s, c});
  }
  cout << prim<ll>(g) << endl;
  return 0;
}
