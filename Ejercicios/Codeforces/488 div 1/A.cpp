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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt


set<ii> S(vector<ii>& P) {
    set<ii> S1;
    repx(i, -100, 101) repx(j, -100, 101) {
        int neg = 0, pos = 0;
        bool in = 0;
        rep(k, 4) {
            ii dX1 = { P[k].ff - P[(k + 1) % 4].ff, P[k].ss - P[(k + 1) % 4].ss };
            ii dX2 = { P[k].ff - i, P[k].ss - j };
            if(dX1.ff * dX2.ss - dX1.ss * dX2.ff > 0) pos++;
            else if(dX1.ff * dX2.ss - dX1.ss * dX2.ff < 0) neg++;
            else if(dX1.ff * dX2.ff >= 0 and dX1.ss * dX2.ss >= 0 and
                abs(dX2.ff) <= abs(dX1.ff) and abs(dX2.ss) <= abs(dX1.ss)) in = 1;
        }
        // if(in) cout<<i<<' '<<j<<'\n';
        if(in or neg == 4 or pos == 4) S1.insert({i, j});
    }
    return S1;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<ii> P1(4); rep(i, 4) cin>>P1[i].ff>>P1[i].ss;
    vector<ii> P2(4); rep(i, 4) cin>>P2[i].ff>>P2[i].ss;
    set<ii> S1 = S(P1);
    set<ii> S2 = S(P2);
    bool inter = 0;

    // for(auto u: S1) cout<<"("<<u.ff<<' '<<u.ss<<"), "; cout<<'\n';
    // for(auto u: S2) cout<<"("<<u.ff<<' '<<u.ss<<"), "; cout<<'\n';
    
    for(auto u: S1) {
        if(S2.count(u)) inter = 1;
    }
    if(inter) cout<<"YES\n";
    else cout<<"NO\n";


    return 0;
}