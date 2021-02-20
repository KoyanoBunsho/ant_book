#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i=0; i<n; i++)

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    double lo = 0, hi = 1000;
    rep(i, 50){
        double mid = (hi+lo)/2;
        if(a*mid+b*sin(c*mid*M_PI)<100)lo=mid;
        else hi=mid;
    }
    cout << fixed << setprecision(15) << lo << endl;
    return 0;
}