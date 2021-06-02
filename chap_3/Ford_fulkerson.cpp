#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

const int INF = 1 << 30;
struct graph {
  typedef long long flow_type;
  struct edge {
    int src, dst;
    flow_type capacity, flow;
    size_t rev;
  };
  int n;
  vector<vector<edge>> adj;
  graph(int n) : n(n), adj(n) {}
  void add_edge(int src, int dst, flow_type capacity) {
    adj[src].push_back({src, dst, capacity, 0, adj[dst].size()});
    adj[dst].push_back({dst, src, 0, 0, adj[src].size() - 1});
  }
  int max_flow(int s, int t) {
    vector<bool> visited(n);
    function<flow_type(int, flow_type)> augment = [&](int u, flow_type cur) {
      if (u == t)
        return cur;
      visited[u] = true;
      for (auto &e : adj[u]) {
        if (!visited[e.dst] && e.capacity > e.flow) {
          flow_type f = augment(e.dst, min(e.capacity - e.flow, cur));
          if (f > 0) {
            e.flow += f;
            adj[e.dst][e.rev].flow -= f;
            return f;
          }
        }
      }
      return flow_type(0);
    };
    rep(u, n) {
      for (auto &e : adj[u])
        e.flow = 0;
    }
    flow_type flow = 0;
    while (1) {
      fill(visited.begin(), visited.end(), false);
      flow_type f = augment(s, INF);
      if (f == 0)
        break;
      flow += f;
    }
    return flow;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  graph g(n);
  rep(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    g.add_edge(u, v, w);
  }
  cout << g.max_flow(0, n - 1);
}
