#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second



int main(){
    int n, m, k; cin>>n>>m>>k;
    int mat[n][m]; rep(i,n) rep(j,m) cin>>mat[i][j];
    vector<vector<int>> G(n, vector<int>(m, 0)); // mensajes que envia al chat
    vector<int> A(m, 0); // mensajes que recibe el chat
    rep(i, k) {
        int a, b; cin>>a>>b; a--, b--;
        A[b]++; G[a][b]++;
    }
    rep(i, n) {
        int sum = 0;
        rep(j, m) sum += mat[i][j]? A[j] - G[i][j] : 0;
        cout<<sum<<" ";
    }
    cout<<"\n";





    return 0;
}