#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

char mat[303][303];
int n;
int cont(int x, int i, int j, int d){
    int ans=0;//x==1 se mueve en i, x==0 se mueve en j
    rep(k,3){
        if(x && d==1){
            if(i+k+1<n && mat[i+k+1][j]=='X') ans++;
            else break;     
        }
        if(x && d==-1){
            if(0<=i-k-1 && mat[i-k-1][j]=='X') ans++;
            else break;
        }
        if(!x && d==1){
            if(j+k+1<n && mat[i][j+k+1]=='X') ans++;
            else break;
        }
        if(!x && d==-1){
            if(j-k-1 && mat[i][j-k-1]=='X') ans++;
            else break; 
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n;
        rep(i,n) rep(j,n) cin>>mat[i][j];
        rep(i,n){
            rep(j,n){
                if(mat[i][j]!='X') continue;
                int conti=cont(1,i,j,1)+cont(1,i,j,-1)+1;
                int contj=cont(0,i,j,1)+cont(0,i,j,-1)+1;
                cout<<"i: "<<i<<", j: "<<j<<", conti: "<<conti<<", contj: "<<contj<<"\n";
                if(conti+1>=3 && contj+1>=3) mat[i][j]='O';
            }
        }
        rep(i,n) {
            rep(j,n) cout<<mat[i][j];
            cout<<"\n";
        }
    }



    return 0;
}