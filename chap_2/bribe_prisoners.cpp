#include<bits/stdc++.h>
using namespace std;

const int MAX_Q = 100005;
int P, Q, A[MAX_Q+2];
int dp[MAX_Q+1][MAX_Q+2];

int main(){
    cin >> P >> Q;
    for(int i=0; i<Q; i++)cin >> A[i];
    A[0] = 0;
    A[Q+1] = P+1;
    for(int q=0; q<=Q; q++){
        dp[q][q+1]=0;
    }
    for(int w=2; w<=Q+1; w++){
        for(int i=0; i+w<=Q+1; i++){
            int j=i+w, t=INT_MAX;
            for(int k=i+1; k<j; k++){
                t=min(t, dp[i][k]+dp[k][j]);
            }
            dp[i][j]=t+A[j]-A[i]-2;
        }
    }
    cout << dp[0][Q+1] << endl;
    return 0;
}