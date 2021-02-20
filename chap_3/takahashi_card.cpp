#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i=0; i<n; i++)

ll dp[55][3000][55];

int main(){
    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    rep(i, n){
        rep(s, n*a+1){
            rep(k, n+1){
                if (dp[i][s][k]==0) continue;
                dp[i+1][s][k] += dp[i][s][k];
                dp[i+1][s+x[i]][k+1] += dp[i][s][k];
            }
        }
    }
    ll ans = 0;
    for(int k=1; k<=n; k++)ans += dp[n][a*k][k];
    cout << ans << endl;
    return 0;
}