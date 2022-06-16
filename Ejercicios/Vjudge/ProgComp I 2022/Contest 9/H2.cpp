#pragma GCC optimize("Ofast")
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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt





int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    repx(cas, 1, t + 1) {
        ll n, d; cin>>n>>d;
        vi A(n); rep(i, n) cin>>A[i];
        map<ll, set<ll>> S1, S2;
        rep(i, (1LL << (n / 2))) {
            ll suma = 0, cant = 0;
            rep(j, n / 2) if(i & (1LL << j)) suma += A[j], cant++;
            if(!S1.count(suma)) S1[suma] = {};
            S1[suma].insert(cant);
        } 

        rep(i, (1LL << ((n + 1) / 2))) {
            ll suma = 0, cant = 0;
            rep(j, (n + 1) / 2) if(i & (1LL << j)) suma += A[j + n / 2], cant++;
            if(!S1.count(suma)) S2[suma] = {};
            S2[suma].insert(cant);
        }

        ll ans = -1;
        bool mul = 0;
        for(auto& [a, b]: S1) {
            if(S2.count(d - a)) {
                // cout<<S1[a].size()<<' '<<S2[d - a].size()<<' '<<ans<<'\n';
                if(S1[a].size() * S2[d - a].size() != 1) mul = 1;
                else if(ans != -1 and ans != *S1[a].begin() + *S2[d - a].begin()) mul = 1;
                else ans = *S1[a].begin() + *S2[d - a].begin();  
            }
        }
        if(mul) cout<<"Case #"<<cas<<": AMBIGIOUS\n";
        else if(ans == -1) cout<<"Case #"<<cas<<": IMPOSSIBLE\n";
        else cout<<"Case #"<<cas<<": "<<ans<<'\n';


    }




    return 0;
}