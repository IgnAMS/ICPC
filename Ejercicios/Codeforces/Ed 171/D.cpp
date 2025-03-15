#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    ll A[n]; rep(i, n) cin>>A[i];


    vl Inds = {0, 1};
    rep(i, n) Inds.pb(Inds.back() + n - i);

    ll acc = 0;
    rep(i, n) acc += A[i] * ll(n - i);

    vl Acc = {0};
    vl Ans = {0};
    rep(i, n) {
        Ans.pb(acc);
        acc -= A[i] * ll(n - i);
        Acc.pb(Acc.back() + Ans[i + 1]);
    }
    



    rep(i, n + 1) cout<<Inds[i]<<' '<<Inds[i + 1] - 1<<' '<<Ans[i]<<' '<<Acc[i]<<'\n'; cout<<'\n';
    


    ll q; cin>>q;
    while(q--) {
        ll l, r; cin>>l>>r;
        ll left = prev(prev(upper_bound(Inds.begin(), Inds.end(), l))) - Inds.begin();
        ll right = prev(upper_bound(Inds.begin(), Inds.end(), r)) - Inds.begin();
        
        ll ans = Acc[right - 1] - Acc[left];
        cout<<l<<' '<<r<<" estan totalmente contenidos en "<<left<<' '<<right<<" con "<<ans<<'\n';
        cout<<Inds[left]<<' '<<Inds[right]<<'\n';
        if(Inds[left + 1] < l) {
            cout<<"debo sumar un prefijo\n";
        }
        
        // Esto siempre se cumple xd
        // if(Inds[right] <= r) 
        cout<<"debo sumar un sufijo\n";
        
    }


    return 0;
}