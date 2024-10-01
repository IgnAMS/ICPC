#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
#define ff first
#define ss second



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll A[n]; rep(i, n) cin>>A[i];
    vector<ii> D; D.emplace_back(0, 0);
    ll ans = 0, prev = 0; 
    rep(i, n) if(i % 2){
        ll a = A[i - 1];
        ll b = A[i];
        prev = ans;
        ans += min(a, b); 
        // Casos bases
        if(b == a){
            ans += D.back().ss;
            if(D.back().ff != 0) D.emplace_back(0, 0);
            D.back().ss += 1;
            continue;
        }
        if(a > b) D.emplace_back(a - b, 0);
        b -= a;
        ll cont = 0;
        // cout<<"D: "; rep(i, D.size()) cout<<D[i].ff<<' '; cout<<'\n';
        for(int j = D.size() - 1; j >= 0 and b >= 0; j--){
            if(b >= D[j].ff){
                if(D[j].ff == 0) { // gano acumulados
                    ans += D[j].ss;
                    cont += D[j].ss;
                } 
                else { // gano muchos chicos y uno grande 
                    ans += D[j].ff;
                    cont = 0;
                } 
                D.pop_back();
            }
            else if(b < D[j].ff){
                ll aux = D[j].ff;
                D[j].ff -= b;
                ans += b;
                cont = 0;
                b -= aux;
                break;
            }
            b -= D[j].ff;
        }
        cout<<ans - prev<<'\n';
        // cout<<i<<' '<<b<<'\n';
        if(b > 0) { D.clear(); D.emplace_back(0, 0); }
        else D.push_back(ii(0, cont + 1)); 
    }
    cout<<ans<<'\n';





    return 0;
}