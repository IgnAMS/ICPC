#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int m; cin>>m;
        int matrix[2][m]; rep(i,2) rep(j, m) cin>>matrix[i][j];
        int aux1=0, aux2=0; rep(i, m-1) aux2 += matrix[1][i];
        int ans = aux2; 
        for(int i = m - 1; i>=1; i--){
            aux1 += matrix[0][i];
            aux2 -= matrix[1][i-1];
            //cout<<aux1<<' '<<aux2<<'\n';
            ans = min(ans, max(aux1, aux2));
        }
        cout<<ans<<'\n';
    }


    return 0;
}