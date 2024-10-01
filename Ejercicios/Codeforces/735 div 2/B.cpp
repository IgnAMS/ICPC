#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(long long i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll,ll> ii;
#define ff first
#define ss second


int main(){
    int t; cin>>t;
    while(t--){
        ll n, k; cin>>n>>k;
        vector<ll> A(n); vector<ii> B(n, {0, 0});
        vector<ll> ceros;
        rep(i,n) { 
            cin>>A[i]; 
            B[i] = {A[i], i + 1};
            if(A[i] == 0) ceros.push_back(i);
        }
        
        sort(B.begin(), B.end()); // n * log n
        ll ans = -10000000000;
        // Caso borde de los 0`s
        if(ceros.size() >= 2) ans = max(ans, ceros[ceros.size() - 1] * ceros[ceros.size() - 2]); 
        
        // Casos generales
        rep(i,n-1) {
            // cout<<B[i].ss<<' '<<B[i+1].ss<<' '<<B[i].ff <<' '<<B[i+1].ff<<'\n';
            ans = max(ans, B[i].ss * B[i+1].ss - k * (B[i].ff | B[i+1].ff));
            ans = max(ans, ll(i + 1) * ll(i + 2) - k * (A[i] | A[i+1]));
            
            // aprox n * n - n * n = 0
            // n * (n - 1) - n * (n + 1) peor de los casos 
            ans = max(ans, ll(i + 1) * ll(n)  - k * (A[n-1] | A[i]));
            // cout<<ll(i) * ll(i + 1) - k * (A[i] | A[i+1]); 
        }

        // reviso los ultimos 300 casos
        repx(i, max(n - 300, 0LL), n){
            rep(j, i) ans = max(ans, ll(j + 1) * ll(i + 1) - k * (A[i] | A[j]));
        }
        cout<<ans<<'\n';
    }


    return 0;
}