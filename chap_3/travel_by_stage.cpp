#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
const int MAX_M = 100005;
const int INF = 10000005;
int n, m, a, b;
int t[MAX_N];
int d[MAX_M][MAX_M];
double dp[1<<MAX_N][MAX_M];

int main(){
    for(int i=0; i<1<<n; i++){
        fill(dp[i], dp[i]+m, INF);
    }
    dp[(1<<n)-1][a-1]=0;
    double res=INF;
    for(int S=(1<<n)-1; S>=0; S--){
        res=min(res, dp[S][b-1]);
        for(int v=0; v<m; v++){
            for(int i=0; i<n; i++){
                if(S>>i&1){
                    for(int u=0; u<m; u++){
                        if(d[v][u]>=0){
                            dp[S&-(1<<i)][u]=min(dp[S&~(1<<i)], dp[S][v]+(double)d[v][u]/t[i]);
                        }
                    }
                }
            }
        }
    }
    if(res==INF){
        cout << "Impossible" << endl;
    }else{
        cout << res << endl;
    }
}