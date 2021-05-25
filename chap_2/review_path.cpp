#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

struct edge {
  int to, cost;
};
typedef vector<vector<edge>> AdjList;
AdjList graph;
typedef pair<int, int> P;
vector<int> dist;
vector<int> prever;
const int MAX_V = 10005;
const int INF = 1000000007;
int prev[MAX_V];
int d[MAX_V], V;
bool used[MAX_V];
int cost[MAX_V][MAX_V];

void dijkstra(int n, int s) {
  dist = vector<int>(n, INF);
  prever = vector<int>(n, -1);
  dist[s] = 0;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, s));
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (dist[v] < p.first) {
      continue;
    }
    rep(i, graph[v].size()) {
      edge e = graph[v][i];
      if (dist[e.to] > dist[v] + e.cost) {
        dist[e.to] = dist[v] + e.cost;
        prever[e.to] = v;
        que.push(P(dist[e.to], e.to));
      }
    }
  }
}
vector<int> get_path(int t) {
  vector<int> path;
  for (; t != -1; t = prever[t])
    path.push_back(t);
  reverse(path.begin(), path.end());
  return path;
}

int main() {
  int n, m;
  cin >> n >> m;
  graph = AdjList(n);
  rep(i, m) {
    int from, to, cost;
    cin >> from >> to >> cost;
    graph[from].push_back((edge){to, cost});
  }
  dijkstra(n, 0);
  vector<int> ans = get_path(3);
  rep(i, ans.size()) { cout << ans[i] << endl; }
  return 0;
}
