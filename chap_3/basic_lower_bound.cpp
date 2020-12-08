#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1000005;
int n, k;
int a[MAX_N]

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++)cin >> a[i];
    int lb = -1;
    int ub = n;
    while(ub - lb > 1){
        int mid = (lb+ub) / 2;
        if(a[mid]>=k){
            ub = mid;
        }else{
            lb = mid;
        }
    }
    cout << ub << endl;
}