#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
int n;
int A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];
long long CD[MAX_N*MAX_N];

int main(){
    cin >> n;
    for(int i=0; i<n; i++)cin >> A[i];
    for(int i=0; i<n; i++)cin >> B[i];
    for(int i=0; i<n; i++)cin >> C[i];
    for(int i=0; i<n; i++)cin >> D[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            CD[i*n+j]=C[i]+D[j];
        }
    }
    sort(CD, CD+n*n);
    long long res=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cd=-(A[i]+B[j]);
            res += upper_bound(CD, CD+n*n, cd)-lower_bound(CD, CD+n*n, cd);
        }
    }
    cout << res << endl;
    return 0;
}