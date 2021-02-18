#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define ll long long

const int MOD = 1000000007;
int dp[110000];
int sum[110000];

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> f(n);
    rep(i, n)cin >> f[i], --f[i];
    vector<int> fnum(m, 0);
    vector<int> L(n+1, 0);
    int left = 0;
    rep(right, n){
        fnum[f[right]]++;
        while(left<right && fnum[f[right]]>1){
            --fnum[f[left]];
            ++left;
        }
        L[right+1]=left;
    }
    dp[0]=1;
    sum[0]=0;
    sum[1]=1;
    for(int i=1; i<=n; i++){
        dp[i] = (sum[i]-sum[L[i]]+MOD)%MOD;
        sum[i+1]=(sum[i]+dp[i])%MOD;
    }
    cout << dp[n] << endl;
    return 0;
}