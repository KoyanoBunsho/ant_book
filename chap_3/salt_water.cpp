#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define ll long long

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> w(n), p(n);
    rep(i, n)cin >> w[i] >> p[i];
    double lo = 0.0, hi = 100.0;
    rep(i, 50){
        double mi = (lo+hi)/2;
        vector<double> tmp(n);
        rep(j, n){
            tmp[j] = (p[j]-mi)*w[j];
        }
        sort(tmp.begin(), tmp.end(), greater<double>());
        double sum=0.0;
        rep(j, k)sum+=tmp[j];
        if(sum<0.0)hi=mi;
        else lo=mi;
    }
    cout << fixed << setprecision(9)<<hi<<endl;
    return 0;
}