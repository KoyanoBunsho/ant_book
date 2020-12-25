#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
int n;
int d[MAX_N][MAX_N];
int dp[1<<MAX_N][MAX_N];

int rec(int S, int v){
    if(dp[S][v]>=0){
        return dp[S][v];
    }
    if(S==(1<<n)-1&&v==0){
        return dp[S][v]=0;
    }
    int res=INF;
    for(int u=0; u<n; u++){
        if(!(S>>u&l)){
            res=min(res, rec(S|1<<u, u)+d[v][u]);
        }
    }
    return dp[S][v]=res;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
}