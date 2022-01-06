#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    vi P(n); rep(i, n) cin>>P[i];

    multiset<ll> prev, free;
    rep(i, n) {
        prev.insert(-P[i]);
        if(prev.size() >= k + 1 + free.size() * k) { // tiene al menso uno
            free.insert(-*prev.begin());
            prev.erase(prev.find(*prev.begin()));
        }
        while(!free.empty() and *free.begin() < -*prev.begin()) { // O(1) amortizadoo
            ll aux = *free.begin();
            free.insert(-*prev.begin());
            free.erase(free.find(aux));
            prev.erase(prev.find(*prev.begin()));
            prev.insert(-aux);
        }
        // cout<<"prev: "; for(auto u : prev) cout<<-u<<' '; cout<<'\n';
        // cout<<"freee: "; for(auto u : free) cout<<u<<' '; cout<<"\n\n";
    }
    ll ans = 0; for(auto& u: prev) ans -= u;

    cout<<ans<<'\n';


    return 0;
}