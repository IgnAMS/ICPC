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
        int n; cin>>n;
        int A[n]; rep(i,n) cin>>A[i];
        vector<int> par, imp;
        rep(i, n) {
            if(A[i] % 2 == 0) par.push_back(i);
            else imp.push_back(i);
        }
        if(abs(int(imp.size()) - int(par.size())) > 1) { cout<<-1<<'\n'; continue; }
        ll ans = 0;
        if(imp.size() > par.size()){ // imp debe estar siempre en las posiciones pares
            rep(i, (n+1)/2){
                ans += abs(imp[i] - 2 * i);
            }
        }
        else if(imp.size() < par.size()){
            rep(i, (n+1)/2){
                ans += abs(par[i] - 2 * i);
            }
        }
        else {
            ll aux1 = 0, aux2 = 0;
            rep(i, n/2) aux1 += abs(par[i] - 2 * i);
            rep(i, n/2) { aux2 += abs(imp[i] - 2 * i); }
            ans = min(aux1, aux2);
        }
        cout<<ans<<'\n';

    }


    return 0;
}