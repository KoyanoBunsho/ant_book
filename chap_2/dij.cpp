#include<bits/stdc++.h>
using namespace std;

const int MAX_V=10005;
int const[MAX_V][MAX_V];
int d[MAX_V];
bool used[MAX_V];
int V;

void dijkstra(int s){
    fill(d, d+V, INF);
    fill(used, used+V, false);
    d[s]=0;
    while(true){
        int v=-1;
        for(int u=0; u<V; u++){
            if(!used[u]&&(v==-1||d[u]<d[v]))v=u;
        }
        if(v==-1)break;
        used[v]=true;
        for(int u=0; u<V; u++){
            d[u]=min(d[u], d[v]+cost[v][u]);
        }
    }
}

int main(){
    return 0;
}