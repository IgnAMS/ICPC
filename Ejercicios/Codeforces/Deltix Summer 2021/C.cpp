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
    int n; cin>>n;
    ll A[n]; rep(i, n) cin>>A[i];
    ll ans = 0;
    ll a = 0, b = 0, c = 0, ind;
    vector<ll> D = {0};
    rep(i, n) if(i % 2 == 1){
        if(A[i] > A[i-1]){
            ans += A[i-1] + D.back() + min(a, A[i] - A[i-1]); D.pop_back();
            if(a >= A[i] - A[i-1]) {
                a -= A[i] - A[i-1];
                ll aux = D.back();
                if(a == 0) {
                    ll aux = D.back();   
                    ans += D.back(); D.pop_back();
                    D.push_back(aux + 1); // Mezcla de mega conjuntos
                }
                else D.push_back(1); // Un conjunto grande
            }
            else a = 0, D.push_back(0);
        }
        // El D.back no se usa solo en este caso
        else if(A[i-1] > A[i]){
            a += A[i-1] - A[i];
            ans += A[i];
            D.push_back(1);
        }
        else{ // A[i-1] == A[i]
            a += A[i-1] - A[i];
            ll aux = D.back();
            ans += A[i] + D.back(); D.pop_back();
            D.push_back(aux + 1); 
        }
        cout<<i<<' '<<ans<<'\n';
        // if(i == 3) cout<<a<<' '<<c<<'\n';
    }
    cout<<ans<<'\n';




    return 0;
}