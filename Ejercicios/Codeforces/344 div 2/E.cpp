#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

ll func(ll x, vi& A, vi& Acc, ll i) { return A[x] * (i - x) - Acc[i] + Acc[x]; }

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vi A(n); rep(i, n) cin>>A[i];
    vi Acc(n + 1, 0);
    rep(i, n) Acc[i] = A[i];
    repx(i, 1, n) Acc[i] += Acc[i - 1];
    // rep(i, n) cout<<Acc[i]<<' '; cout<<'\n';

    set<ll> S;
    S.insert(0); 
    map<ll, ll> mp;
    ll mx = A[0], sumprod = 0, ans = -1e17;
    mp[0] = n;
    repx(i, 1, n + 1) sumprod += i * A[i - 1];
    rep(i, n) {
        while(mp[*S.begin()] <= i) S.erase(*S.begin());
        if(A[i] > mx) {
            mx = A[i];
            mp[i] = n;
            for(auto u: S) {
                // cout<<func(u, A, Acc, i) / (mx - A[u])<<'\n';
                mp[u] = min(mp[u], i + max(0LL, (func(u, A, Acc, i)) / (mx - A[u])));
                // cout<<"eliminare a "<<A[u]<<" el turno "<<mp[u]<<'\n';
            }
            S.insert(i);
        }
        ll a = *S.begin();
        // cout<<a<<", "<<A[a]<<": "<<func(a, A, Acc, i)<<'\n';
        ans = max(ans, sumprod + func(a, A, Acc, i));
    } 
    
    ll mn = A[n - 1];
    vi Acc2(n + 1, 0);
    rep(i, n) Acc2[i + 1] = Acc2[i] + A[i]; 
    S.clear();
    S.insert(-n + 1LL);
    mp.clear();
    mp[n - 1] = -1;
    for(ll i = n - 1; i >= 0; i--) {
        // cout<<i<<' '<<-*S.begin()<<' '<<mp[-*S.begin()]<<'\n';
        while(mp[-*S.begin()] >= i) S.erase(S.begin());
        if(A[i] < mn) {
            // cerr<<"aaaaa\n";
            mn = A[i];
            mp[i] = -1;
            for(auto u: S) {
                // cout<<-u<<", "<<A[-u]<<": "<<func(-u, A, Acc2, i)<<' '<<(A[-u] - mn)<<'\n';
                // if(func(-u, A, Acc2, i) <= 0) mp[-u] = n;
                mp[-u] = max(mp[-u], i - max(0LL, (func(-u, A, Acc2, i)) / (A[-u] - mn)));
                // cout<<"eliminare a "<<A[-u]<<" el turno "<<mp[-u]<<'\n';
            }
            S.insert(-i);
        }
        ll a = -*S.begin();
        // cout<<a<<", "<<A[a]<<": "<<func(a, A, Acc2, i)<<'\n';
        ans = max(ans, sumprod + func(a, A, Acc2, i));
    }


    cout<<ans<<'\n';




    return 0;
}