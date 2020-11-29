#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
const int INF = 1000005;
int N, R;
struct edge {int from, to, cost;};
vector<edge> G[MAX_N];
typedef pair<int, int> P;

int dist[MAX_N];
int dist2[MAX_N];

int main(){
    priority_queue<P, vector<P>, greater<P>> que;
    fill(dist, dist+N, INF);
    fill(dist2, dist2+N, INF);
    dist[0]=0;
    que.push(P(0, 0));
    while(!que.empty()){
        P p=que.top(); que.pop();
        int v=p.second, d=p.first;
        if(dist2[v]<d)continue;
        for(int i=0; i<G[v].size(); i++){
            edge &e = G[v][i];
            int d2 = d+e.cost;
            if(dist[e.to]>d2){
                swap(dist[e.to], d2);
                que.push(P(dist[e.to], e.to));
            }
            if(dist2[e.to]>d2&&dist[e.to]<d2){
                dist2[e.to]=d2;
                que.push(P(dist2[e.to], e.to));
            }
        }
    }
    cout << dist2[N-1] << endl;
    return 0;
}