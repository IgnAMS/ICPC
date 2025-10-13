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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll A[n];
    map<ll, ll> cont;
    set<pll> invcont;
    ll ans = 0;
    rep(i, n) {
        cin>>A[i];
        cont[A[i]] += 1;
        if(cont[A[i]] == 1) invcont.insert({1, A[i]});
        else {
            invcont.erase({cont[A[i]] - 1, A[i]});
            invcont.insert({cont[A[i]], A[i]});
        }

        // cout<<"i: "<<i<<'\n';
        if(cont.size() == 1) ans = i + 1;
        if(cont.size() >= 2) {
            auto r = *invcont.rbegin();
            auto r2 = *next(invcont.rbegin());
            auto l = *invcont.begin();
            auto l2 = *next(invcont.begin());
            // cout<<l.ff<<' '<<l.ss<<'\n';
            // cout<<l2.ff<<' '<<l2.ss<<'\n';
            // cout<<r2.ff<<' '<<r2.ss<<'\n';
            // cout<<r.ff<<' '<<r.ss<<'\n';
            // opcion 1: saco del mas grande
            if(r.ff == r2.ff + 1 and l.ff == r2.ff) ans = i + 1;
            
            // opcion 2: saco del mas chico
            if(l.ff == 1 and l2.ff == r.ff) ans = i + 1;
        }
        // cout<<'\n';
    }
    cout<<ans<<'\n';

    return 0;
}