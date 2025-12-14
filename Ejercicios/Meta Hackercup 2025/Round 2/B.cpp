#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<map>
#include<set>
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

const ll MOD = 998244353;

void solve(int caso) {
    int n, m; cin>>n>>m;
    vl A(n), B(m);
    map<ll, ll> cont;
    rep(i, n) {
        cin>>A[i];
        if(!cont.count(A[i])) cont[A[i]] = 0;
        cont[A[i]]++; 
    }  
    rep(i, m) cin>>B[i];
    sort(B.begin(), B.end());

    /*
    n = 1000000; m = n;
    cont.clear();
    B.resize(m);
    rep(i, n) cont[i+1] = 1; 
    rep(i, m) B[i] = n;
    */

    


    ll l = 0, r = cont.size();
    ll aux = 0;
    while(l < r and aux++ < 50) {
        ll mid = (l + r + 1) / 2;
        // debo chequear si es posible repartir los objetos de B entre
        auto it = cont.rbegin();
        multiset<ll> S;
        rep(i, m) S.insert(B[i]);
        bool posible = true;
        rep(i, mid) {
            multiset<ll> S2;

            ll acc = 0;
            if(S.size() < mid-i) {
                posible=false;
                break;
            }

            // este for es de largo a lo mas M
            while(!S.empty() and acc < (mid-i) * it->ss) {
                ll dif = min(*S.rbegin(), it->ss);
                acc += dif;
                S2.insert(*S.rbegin() - dif);
                S.erase(S.find(*S.rbegin()));
            }
            if(acc < (mid-i) * it->ss) {
                posible = false;
                break;
            }
            for(auto u: S2) if(u != 0) S.insert(u);
            it++;
        }
        // cerr<<l<<" "<<r<<" "<<mid<<" "<<posible<<"\n";

        if(posible) l = mid;
        else r = mid - 1;
    }
    // n * m * log2(n)
    // cerr<<l<<" "<<r<<"\n\n";

    ll ans = 0;
    auto it = cont.rbegin();
    rep(i, l) {
        ans += it->ss;
        it++;
    }
    cout<<"Case #"<<caso<<": "<<ans<<"\n";
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    repx(i, 1, t + 1) solve(i);
    
    return 0;
}