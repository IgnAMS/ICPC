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
    vector<ll> D;
    ll ans = 0, prev = 0; 
    rep(i, n) if(i % 2){
        ll a = A[i - 1];
        ll b = A[i];
        prev = ans;
        ans += min(a, b);   
        b -= a;
        bool oc = 0;
        // cout<<"D["<<i<<"]: "; rep(i, D.size()) cout<<D[i]<<' '; cout<<'\n';
        ll ind = D.size();
        for(int j = D.size() - 1; j >= 0 and b >= 0; j--){
            if(b >= D[j]){
                if(D[j] == 0) ans++;
                else if(D[j] == -1) continue;
                else {
                    ans += D[j], b -= D[j], D[j] = -1, D[j+1] = (b == 0? 0: -1);
                    ind = j;
                }
            }
            else if(b < D[j]){
                ans += b;
                ll aux = D[j];
                D[j] -= b;
                oc = 1;
                if(b != 0) ind = j + 1;
                b -= aux;
                if(D[j] == 0) D[j] = -1;
            }
        }
        // cout<<"Elimino: "<<D.size() - ind<<'\n';
        int aux = D.size();
        rep(i, aux - ind) D.pop_back();
        // cout<<ans - prev<<'\n';
        if(b > 0) D.clear();
        else { if(!oc and b != 0) D.push_back(-b); D.push_back(0); }
    }
    
    // cout<<"D["<<n+1<<"]: "; rep(i, D.size()) cout<<D[i]<<' '; cout<<'\n';
    cout<<ans<<'\n';





    return 0;
}