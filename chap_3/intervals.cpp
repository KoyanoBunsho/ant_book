#include<bits/stdc++.h>
using namespace std;

int N, K;
int a[MAX_N], b[MAX_N], w[MAX_N];

int main(){
    vector<int> x;
    for(int i=0; i<N; i++){
        x.push_back(a[i]);
        x.push_back(b[i]);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    int m=x.size();
    int s=m, t=s+1;
    V=t+1;
    int res=0;
    add_edge(s, 0, K, 0);
    add_edge(m-1, t, K, 0);
    for(int i=0; i+1<m; i++){
        add_edge(i, i+1, INF, 0);
    }
    for(int i=0; i<N; i++){
        int u=find(x.begin(), x.end(), a[i])-x.begin();
        int v=find(x.begin(), x.end(), b[i])-x.begin();
        add_edge(v, u, 1, w[i]);
        add_edge(s, v, 1, 0);
        add_edge(u, t, 1, 0);
        res-=w[i];
    }
    res += min_cost_flow(s, t, K+N);
    cout << -res << endl;
}