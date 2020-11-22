#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
const int MAX_W = 100005;
int dp[MAX_N][MAX_W];
int n, W;
int w[MAX_N], v[MAX_N];

int main(){
    cin >> n >> W;
    for(int i=0; i<n; i++)cin >> w[i] >> v[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<=W; j++){
            if(j<w[i])dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = max(dp[i][j], dp[i+1][j-w[i]]+v[i]);
        }
    }
    cout << dp[n][W] << endl;
}