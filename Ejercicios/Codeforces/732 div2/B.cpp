#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b;i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        int cont[m][26]; memset(cont, 0, sizeof cont);
        const int aux = n;
        vector<vector<vector<bool>>> palabras(m, vector<vector<bool>>(26, vector<bool>(n, 0))); // dado un indice i, una letra j da un vector
        vector<string> A(n);
        rep(i,n) {
            cin>>A[i];
            rep(j, m) {
                palabras[j][A[i][j] - 'a'][i] = true;
                cont[j][A[i][j] - 'a']++;
            }
        }
        int cont2[m][26]; memset(cont2, 0, sizeof cont2);
        vector<string> B(n);
        rep(i,n-1){
            cin>>B[i]; 
            rep(j, m){
                cont2[j][B[i][j] - 'a']++;
            }
        }
        cerr<<"morisi acax3\n";
        vector<bool> ans(n, 0);
        //cout<<cont[0][0]<<' '<<cont2[0][0]<<'\n';
        rep(i, m) rep(j, 26){
            //cout<<cont[i][j]<<' '<<cont2[i][j]<<'\n';
            if(cont[i][j] == cont2[i][j] and cont[i][j] != 0) {
                rep(k, n) ans[k] =  ans[k] or palabras[i][j][k];
                // cout<<"anado: ";
                // rep(k, n) if(palabras[i][j][k]) cout<<k<<' '; cout<<'\n';
            }
        }
        bool flag = 0;
        rep(i,n) if(!flag and !ans[i]) {
            flag = 1;
            cout<<A[i]<<'\n';
        }
        if(!flag) cout<<A[0]<<'\n';

    }






    return 0;
}