#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

const int MAX_N = 200005;

int N, A[MAX_N], k, n;

int rev[MAX_N*2], sa[MAX_N*2];
int rank_arr[MAX_N+1], tmp[MAX_N+1];

bool compare_sa(int i, int j){
    if(rank_arr[i] != rank_arr[j]) return rank_arr[i] < rank_arr[j];
    else{
        int ri = i + k <= n? rank_arr[i+k]: -1;
        int rj = j + k <= n ? rank_arr[j+k]:-1;
        return ri < rj;
    }
}

void construct_sa(int *S, int n, int *sa){
    for(int i=0; i<=n; i++){
        sa[i] = i;
        rank_arr[i] = i < n ? S[i]: -1;
    }
    for(int k=1; k<=n; k*=2){
        sort(sa, sa+n+1, compare_sa);
        tmp[sa[0]] = 0;
        for(int i=1; i<=n; i++){
            tmp[sa[i]] = tmp[sa[i-1]]+(compare_sa(sa[i-1], sa[i])?1:0);
        }
        for(int i=0; i<=n; i++){
            rank_arr[i] = tmp[i];
        }
    }
}

int main(){
    cin >> N;
    rep(i, N) cin >> A[i];
    reverse_copy(A, A+N, rev);
    construct_sa(rev, N, sa);
    int p1;
    rep(i, N){
        p1 = N - sa[i];
        if(p1>=1 && N - p1>=2) break;
    }
    int m = N-p1;
    reverse_copy(A+p1, A+N, rev);
    reverse_copy(A+p1, A+N, rev+m);
    construct_sa(rev, m*2, sa);
    int p2;
    for(int i=0; i<=2*m; i++){
        p2 = p1+m-sa[i];
        if(p2-p1>=1 && N-p2>=1) break;
    }
    reverse(A, A+p1);
    reverse(A+p2, A+N);
    rep(i, N)cout<< A[i] << endl;
}