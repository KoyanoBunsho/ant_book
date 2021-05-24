#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

const int MAX_V = 1005;
const int INF = 1000000007;
int cost[MAX_V][MAX_V];
int d[MAX_V];
bool used[MAX_V];
int V, E;
struct edge {
  int to, cost;
};
typedef pair<int, int> P;
vector<edge> G[MAX_V];

void dijkstra(int s) {
  fill(d, d + V, INF);
  fill(used, used + V, false);
  d[s] = 0;
  while (true) {
    int v = -1;
    rep(u, V) {
      if (!used[u] && (v == -1 || d[u] < d[v]))
        v = u;
    }
    if (v == -1)
      break;
    used[v] = true;
    rep(u, V) { d[u] = min(d[u], d[v] + cost[v][u]); }
  }
}

void dijkstra_p_que(int s) {
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d + V, INF);
  d[s] = 0;
  que.push(P(0, s));
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first)
      continue;
    rep(i, G[v].size()) {
      edge e = G[v][i];
      if (d[e.to] > d[v + e.cost]) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main() {
  cin >> V >> E;
  rep(i, E) {
    int from, to, dist;
    cin >> from >> to >> dist;
    cost[from][to] = dist;
  }
  int start, end;
  cin >> start >> end;
  dijkstra(start);
  cout << d[end] << endl;
  // rep(i, E) { cin >> G[i].to >> G[i].cost; }
  dijkstra_p_que(start);
  cout << d[end] << endl;
  return 0;
}
