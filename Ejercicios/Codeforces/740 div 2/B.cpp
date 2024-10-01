#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
#define ff first
#define ss second



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int a, b; cin>>a>>b;
        vector<bool> B(a+b+1, 0);
        rep(i, a+b+1) {
            int mini = min(i, a+b-i);
            int maxi = max(i, a+b-i);
            // peor de los casos:
            // alguien pierde min(i, (a+b+1)/2), por ende la diferencia deberia ser en el peor de los casos
            // menor o igual a n - peor de los casos
            // mejor de los casos:
            // se reparten equitativamente los puntajes, obteniendo
            // una dif bien baja, para ser exactos de 
            if( <=abs(a-b) and abs(a-b) <= n - min(i, (a+b+1)/2)) B[i] = 1;
        }
        rep(i, a+b+1) cout<<B[i]<<' '; cout<<'\n';
    }





    return 0;
}