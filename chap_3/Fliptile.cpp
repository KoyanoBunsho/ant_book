#include<bits/stdc++.h>
using namespace std;

const int MAX_M = 100005;
const int MAX_N = 100005;
const int dx[5]={-1, 0, 0, 0, 1};
const int dy[5]={0, -1, 0, 1, 0};
int M, N;
int tile[MAX_M][MAX_N];
int opt[MAX_M][MAX_N];
int flip[MAX_M][MAX_N];

int get(int x, int y){
    int c=tile[x][y];
    for(int d=0; d<5; d++){
        int x2=x+dx[d], y2=y+dy[d];
        if(0<=x2 && x2<M && 0<=y2 && y2<N){
            c+=flip[x2][y2];
        }
    }
    return c%2;
}

int calc(){
    for(int i=1; i<M; i++){
        for(int j=0; j<N; j++){
            if(get(i-1, j)!=0){
                flip[i][j]=1;
            }
        }
    }
    for(int j=0; j<N; j++){
        if(get(M-1, j)!=0){
            return -1;
        }
    }
    int res=0;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            res+=flip[i][j];
        }
    }
    return res;
}

int main(){
    int res=-1;
    for(int i=0; i<1<<N; i++){
        memset(flip, 0, sizeof(flip));
        for(int j=0; j<N; j++){
            flip[0][N-j-1]=i>>j&1;
        }
        int num=calc();
        if(num>=0 && (res<0||res>num)){
            res=num;
            memcpy(opt, flip, sizeof(flip));
        }
    }
    if(res<0){
        cout << "IMPOSSIBLE" << endl;
    }else{
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                cout << opt[i][j] << endl;
            }
        }
    }
    return 0;
}