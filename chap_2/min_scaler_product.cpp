#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
const int MAX_N = 1000005;
int v1[MAX_N], v2[MAX_N];

int main(){
    cin >> n;
    for(int i=0; i<n; i++)cin >> v1[i];
    for(int i=0; i<n; i++)cin >> v2[i];
    sort(v1, v1+n);
    sort(v2, v2+n);
    ll ans=0;
    for(int i=0; i<n; i++)ans+=(ll)v1[i]*v2[n-i-1];
    cout << ans << endl;
    return 0;
}