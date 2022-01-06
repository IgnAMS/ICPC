#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        map<int,int> mapa;
        vector<int> A(n);
        rep(i, n) { 
            cin>>A[i];
            if(!mapa.count(A[i])) mapa[A[i]] = 0;
            mapa[A[i]]++;
        } 
        vi ans(n);
        int low = 0, top = n-1;
        if(mapa.count(0)) rep(i, mapa[0]) ans[i] = 0, low++;
        bool sw = 0; // 0 -> izquierda
        for(auto u: mapa){
            if(u.ff == 0) continue;
            if(u.ss == 1) {
                if(!sw) ans[low++] = u.ff;
                else ans[top--] = u.ff;
                sw = !sw;
            }
            if(u.ss >= 2){
                ans[top--] = u.ff;
                rep(i, u.ss - 1) ans[low++] = u.ff;
                sw = 0; 
            }
        }
        ll suma = 0;
        rep(i, n-1) suma += ans[i] * ans[i+1]; 
        cout<<suma<<'\n';
        rep(i, n) cout<<ans[i]<<"\n "[i<n-1];
    }





    return 0;
}