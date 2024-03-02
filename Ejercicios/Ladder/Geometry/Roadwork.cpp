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


struct Event {
    ll s, t, x;
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    vector<Event> E(n);
    rep(i, n) cin>>E[i].s>>E[i].t>>E[i].x;
    vl D(q);
    set<ll> S;
    rep(i, q) {
        cin>>D[i];
        S.insert(D[i]);
    }
    const ll inf = 1e10;
    vl Ans(q, inf);
    
    sort(E.begin(), E.end(), [&](const Event a, const Event b){
        return a.x < b.x;
    });
    
    rep(i, n) {
        vl Elim;
        // iter + E[i].x >= E[i].s  <->  iter >= E[i].s - E[i].x
        auto iter = S.lower_bound(E[i].s - E[i].x);
        while(iter != S.end() and *iter + E[i].x < E[i].t) {
            // cout<<"para la query "<<E[i].s<<' '<<E[i].t<<" "<<E[i].x<<" elimino a "<<(*iter)<<'\n';
            // cout<<*iter + E[i].x<<'\n';
            Elim.pb(*iter);
            iter++;
        }
        for(auto u: Elim) {
            int ind = lower_bound(D.begin(), D.end(), u) - D.begin();
            Ans[ind] = E[i].x;
            S.erase(u);
        }
    }
    rep(i, q) cout<<(Ans[i] == inf? -1: Ans[i])<<'\n'; 

    return 0;
}