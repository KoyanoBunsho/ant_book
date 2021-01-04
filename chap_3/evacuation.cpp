#include<bits/std.c++>
using namespace std;

const int dx[4]={-1, 0, 0, 1}, dy[4]={0, -1, 1, 0};

int X, Y;
char field[MAX_X][MAX_Y+1];

vector<int>dX, dY;
vector<int>pX, pY;
int dist[MAX_X][MAX_Y][MAX_X][MAX_Y];

bool C(int t){
    int d=dX.size(), p=pX.size();
    V=t*d+p;
    for(int v=0; v<V; v++)G[v].clear();
    for(int i=0; i<d; i++){
        for(int j=0; j<p; j++){
            if(dist[dX[i]][dY[i]][pX[j]][pY[j]]>=0){
                for(int k=dist[dX[i]][dY[i]][pX[j]][pY[j]]; k<=t; k++){
                    add_edge((k-1)*d+i, t*d+j);
                }
            }
        }
    }
    return bipartite_matching()==p;
}

void bfs(int x, int y, int d[MAX_X][MAX_Y]){
    queue<int> qx, qy;
    d[x][y]=0;
    qx.push(x);
    qy.push(y);
    while(!qa.empty()){
        x=qx.front(); qx.pop();
        y=qy.front(); qy.pop();
        for(int k=0; k<4; k++){
            int x2=x+dx[k], y2=y+dy[k];
            if(0<=x2 && x2<X && 0<=y2 && y2<Y && field[x2][y2]=='.' && d[x2][y2]<0){
                d[x2][y2]=d[x][y]+1;
                qx.push(x2);
                qy.push(y2);
            }
        }
    }
}