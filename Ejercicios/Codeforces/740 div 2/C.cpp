#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll,ll> ii;
typedef double db;
#define ff first
#define ss second



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cerr<<n<<'\n';
        vector<ll> mini(n); // minimo poder para poder terminar la cueva 
        vector<ll> tam(n);
        vector<ii> A(n);
        rep(i, n){
            int k; cin>>k;
            tam[i] = k;
            int aux;
            int maxi = 0;
            rep(j, k) { 
                cin>>aux;
                maxi = max(maxi, aux - j);
            }
            mini[i] = maxi;
            A[i] = {maxi, k};
        }
        sort(A.begin(), A.end());
        // rep(i, n) cout<<A[i].ff<<' '<<A[i].ss<<'\n'; cout<<'\n';
        ll ans = 0;
        ll acc = 0;
        rep(i, n) { // necesito al menos nivel 12 para entrar
            ans = max(ans, A[i].ff - acc + 1);
            acc += A[i].ss;
        }
        cout<<ans<<'\n';
    }


    return 0;
}