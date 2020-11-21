#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
const int MAX_M = 100005;
int n, m;
char s[MAX_N], t[MAX_M];
int dp[MAX_N+1][MAX_M+1];

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++)cin >> s[i];
    for(int i=0; i<n; i++)cin >> t[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i]==t[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }else{
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}