#include<bits/stdc++.h>
using namespace std;

const int MAX_K = 100005;
int N, K;
int T[MAX_K], X[MAX_K], Y[MAX_K];
int par[MAX_K], rank[MAX_K];

void init(int n){
    for(int i=0; i<n; i++){
        par[i] = i;
        rank[i] = 0;
    }
}

int find(int x){
    if(par[x] == x){
        return x;
    }else{
        return par[x]=find(par[x]);
    }
}

void unite(int x, int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(rank[x]<rank[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(rank[x]==rank[y])rank[x]++;
    }
}
bool same(int x, int y){
    return find(x)==find(y);
}

int main(){
    cin >> N >> K;
    for(int i=0; i<n; i++){
        cin >> X[i] >> Y[i];
    }
    init(N*3);
    int ans = 0;
    for(int i=0; i<K; i++){
        int t=T[i];
        int x=X[i]-1, y=Y[i]-1;
        if(x<0 || N<=x || y<0 || N<=y){
            ans++;
            continue;
        }
        if(t==1){
            if(same(x, y+N) || same(x, y+2*N)){
                ans++;
            }
            else{
                unite(x, y);
                unite(x+N, y+N);
                unite(x+N*2, y+N*2);
            }
        }
        else{
            if(same(x, y) || same(x, y+2*N)) ans++;
            else{
                unite(x, y+N);
                unite(x+N, y+2*N);
                unite(x+2*N, y);
            }
        }
    }
    cout << ans << endl;
    return 0;
}