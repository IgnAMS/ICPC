#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<ll> vl;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)

const int mxN = 1e6+3;
ll mod = 1e9+7;



int main() {
    ll n, h; cin>>n>>h;
    ll K[h]; rep(i, h) cin>>K[i];

    ll F[n + 1]; 
    F[0] = 1;
    repx(i, 1, n + 1) {
        F[i] = (F[i - 1] * ll(i)) % mod;
    }
    ll buenos = 0;
    vl A(n); rep(i, n) A[i] = i + 1;
    vl M(h, 0);
    ll suma = 0; rep(i, h) suma += K[i];
    do {
        // for(auto u: A) cout<<u<<' '; cout<<'\n';
        bool bueno = 1;
        ll curr = suma;
        rep(i, h) {
            bool buenoi = 0;
            rep(j, curr) {
                if(A[n - j - 1] > curr) buenoi = 1; 
            }
            curr -= K[i];
            if(!buenoi) {
                if(h - i - 1 == 2) {
                    for(auto u: A) cout<<u<<' '; cout<<'\n';
                }
                // cout<<"este caso se cae en "<<i<<'\n';
                bueno = 0;
                M[h - i - 1]++; 
                break;
            }
        }
        // if(!bueno) {
        //     for(auto u: A) cout<<u<<' '; cout<<'\n';
        // }
        buenos += bueno;
    } while(next_permutation(A.begin(), A.end()));
    
    
    for(auto u: M) cout<<u<<'\n';
    ll last = 0;
    ll ans = 0;
    ll acc = 0;
    rep(i, h) {
        // ll aux = F[acc + K[i]] * F[n - acc - K[i]] % mod - F[K[i]] * last % mod;
        ll aux = (F[acc + K[i]] - (F[K[i]] * last % mod) + mod) % mod;
        aux = (aux * F[n - K[i] - acc]) % mod;
        // cout<<F[K[i]] * last<<' '<<F[n - K[i] - acc]<<'\n'; 
        cout<<aux<<'\n';
        ans = (ans + aux) % mod;
        acc += K[i];
        last = (F[acc]);
    }
    cout<<buenos<<'\n';
    cout<<(F[n] - ans + mod) % mod<<'\n';


    return 0;
}