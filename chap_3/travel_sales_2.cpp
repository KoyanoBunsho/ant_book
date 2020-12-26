#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
const int INF = 100000005;
int dp[1<<MAX_N][MAX_N];

int main(){
    for(int S=0; S<1<<n; S++){
        fill(dp[S], dp[S]+n, INF)
    }
    dp[(1<<n)-1][0]=0;
    for(int S=(1<<n)-2; S>=0; S--){
        for(int v=0; v<n; v++){
            for(int u=0; u<n; u++){
                if(!(S>>u&1)){
                    dp[S][v]=min(dp[S][v], dp[S|1<<u][u]+d[v][u]);
                }
            }
        }
    }
    cout << dp[0][0] << endl;
}