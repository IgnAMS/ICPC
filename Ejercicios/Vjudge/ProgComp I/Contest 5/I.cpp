#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i,a,b) for(int i=a; i<b;i++)
typedef pair<int,int> ii;
#define ff first
#define ss second

int M[8][8];
int R[8], C[8];

int dr[] = {-1, -1, -2, -2, 1,  1, 2,  2};
int dc[] = { 2, -2, -1,  1, 2, -2, 1, -1};

int posi[70]; int posj[70];

bool backtrack(int i, int j, int x){
    if(R[i] > 260 || C[j] > 260) return 0; 
    if(x==65) return 1;
    if(posi[x] != -1){
        if(abs(i-posi[x]) + abs(j-posj[x]) != 3) return 0;
        else return backtrack(posi[x], posj[x], x+1);
    }
    rep(h, 8){
        int di = dr[h] + i, dj = dc[h] + j;
        if(0<=di && di<8 && 0<=dj && dj<8 && M[di][dj]==-1){
            M[di][dj] = x; R[di]+=x; C[dj]+=x;
            if(backtrack(di, dj, x+1)) return 1;
            M[di][dj] = -1; R[di]-=x; C[dj]-=x;
        }
    }
    return 0;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    memset(C, 0, sizeof C); memset(R, 0, sizeof R);
    rep(i,65) posi[i] = -1, posj[i] = -1;

    rep(i,8) rep(j,8) { 
        cin>>M[i][j];
        if(M[i][j] != -1) {
            posi[M[i][j]] = i, posj[M[i][j]] = j;
            //cout<<M[i][j]<<"\n";
            R[i]+=M[i][j]; C[j]+=M[i][j];
        }
    }
    int x,y; rep(i,8) rep(j,8) if(M[i][j]==1) x=i, y=j;
    backtrack(x, y, 2);
    rep(i,8) { rep(j,8) cout<<M[i][j]<<" "; cout<<"\n"; }

    return 0;
}