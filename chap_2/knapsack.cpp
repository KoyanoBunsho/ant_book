#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N][MAX_N];

int main(){
    cin >> n >> W;
    for(int i=0; i<n; i++)cin >> w[i] >> v[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<=W; j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j+w[i]<=W){
                dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], dp[i][j]+v[i]);
            }
        }
    }
    cout << dp[n][W] << endl;
}