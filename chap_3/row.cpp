#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i=0; i<n; i++)

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> s(n);
    rep(i, n)cin >> s[i];
    rep(i, n){
        if(s[i]==0){
            cout << n << endl;
            return 0;
        }
    }
    int res = 0;
    int right = 0;
    ll mul = 1;
    for(int left=0; left<n; left++){
        while(right<n && mul*s[right]<=k){
            mul *= s[right];
            right++;
        }
        res = max(res, right-left);
        if(right==left)++right;
        else mul /= s[left];
    }
    cout << res << endl;
    return 0;
}