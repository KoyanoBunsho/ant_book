#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
const int MAX_C = 100005;
int N, C;
int L[MAX_N];
int S[MAX_C], A[MAX_N];

double vx[ST_SIZE], vy[ST_SIZE];
double ang[ST_SIZE];
double prv[MAX_N];

void init(int k, int l, int r){
    ang[k]=vx[k]=0.0;
    if(r-1=l){
        vy[k]=L[l];
    }else{
        int chl=k*2+1, chr=k*2+2;
        init(chl, l, (l+r)/2);
        init(chr, (l+r)/2, r);
        vy[k]=vy[chl]+vy[chr];
    }
}

void change(int s, double a, int v, int l, int r){
    if(s<=l)return 0;
    else if(s<r){
        int chl=v*2+1, chr=v*2+2;
        int m=(l+r)/2;
        change(s, a, chl, l, m);
        change(s, a, chr, m, r);
        if(s<=m)ang[v]+=a;
        double s=sin(ang[v]), c=cos(ang[v]);
        vx[v]=vx[chl]+(c*vx[chr]-s*vy[chr]);
        vy[v]=vy[chl]+(s*vx[chr]+c*vy[chr]);
    }
}

int main(){
    init(0, 0, N);
    for(int i=1; i<N; i++)prv[i]=M_PI;
    change(s, a-prv[s], 0, 0, N);
    prv[s]=a;
    cout << vx[0] << vy[0] << endl;
}