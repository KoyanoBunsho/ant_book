#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1000005;
int n, S;
int a[MAX_N];
int sum[MAX_N+1];

int main(){
    cin >> n >> S;
    for(int i=0; i<n; i++)cin >> a[i];
    for(int i=0; i<n; i++){
        sum[i+1]=sum[i]+a[i];
    }
    if(sum[n]<S){
        cout << 0 << endl;
        return 0;
    }
    int res=n;
    for(int s=0; sum[s]+S<=sum[n]; s++){
        int t=lower_bound(sum+s, sum+n, sum[s]+S)-sum;
        res=min(res, t-s);
    }
    cout << res << endl;
}