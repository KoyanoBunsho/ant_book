#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
int n, k;
int w[MAX_N], v[MAX_N];

double y[MAX_N];

bool C(double x){
    for(int i=0; i<n; i++){
        y[i]=v[i]-x*w[i];
    }
    sort(y, y+n);
    double sum=0;
    for(int i=0; i<k; i++){
        sum+=y[n-i-1];
    }
    return sum>=0;
}

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++)cin >> w[i] >> v[i];
    double lb=0, ub=MAX_N;
    for(int i=0; i<100; i++){
        double mid = (lb+ub)/2;
        if(C(mid))lb=mid;
        else ub=mid;
    }
    cout << ub << endl;
}