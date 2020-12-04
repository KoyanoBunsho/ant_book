#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 10005;
int N;
int M[MAX_N][MAX_N];
int a[MAX_N];

int main(){
    cin >> N;
    int res=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> M[i][j];
        }
    }
    for(int i=0; i<N; i++){
        a[i] = -1;
        for(int j=0; j<N; j++){
            if(M[i][j]==1)a[i]=j;
        }
    }
    for(int i=0; i<N; i++){
        int pos=-1;
        for(int j=i; j<N; j++){
            if(a[j]<=i){
                pos=j;
                break;
            }
        }
        for(int j=pos; j>i; i--){
            swap(a[j], a[j-1]);
            res++;
        }
    }
    cout << res << endl;
    return 0;
}