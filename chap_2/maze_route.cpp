#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

const int INF = 1000000007;
const int MAX_N = 105;
const int MAX_M = 105;
int N, M;
int sx, sy;
int gx, gy;
int d[MAX_N][MAX_M];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char maze[MAX_N][MAX_M+1];

int bfs(){
  queue<P> que;
  while(que.size()){
    P p = que.front(); que.pop();
    if(p.first == gx && p.second == gy) break;
    for(int i=0; i<4; i++){
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if(0<=nx && nx<N && 0<=ny && ny<M && maze[nx][ny]!='#' && d[nx][ny] == INF){
        que.push(P(nx, ny));
        d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }
  return d[gx][gy];
}

int main(){
  cin >> N >> M;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> maze[i][j];
    }
  }
  int res = bfs();
  cout << res << endl;
  return 0;
}
