#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
const long long INF = 10000000007;
int n, k;
double L[MAX_N];

bool C(double x){
    int num=0;
    for(int i=0; i<N; i++){
        num += (int)(L[i]/x);
    }
    return num >= K;
}

int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++)cin >> L[i];
    double lb=0, ub=INF;
    for(int i=0; i<100; i++){
        double mid=(lb+ub)/2;
        if(C(mid)) lb=mid;
        else ub=mid;
    }
    cout << floor(ub*100)/100 << endl;
}