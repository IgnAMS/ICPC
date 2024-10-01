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
    while(t--) {
        int n; cin>>n;
        vector<vi> P(n, vi(2));
        rep(i, n) cin>>P[i][0]>>P[i][1];

        vector<vi> E; // Eventos
        rep(i, n) {
            E.push_back({P[i][0], 0, P[i][1], i}); // abrir evento
            E.push_back({P[i][1], 1, P[i][1], i}); // cerrar evento
        }
        sort(E.begin(), E.end());

        int comps = 0;
        set<ii> S;
        int last = -1;
        vi Ans(n, 0);
        ll mxsum = 0;

        for(auto e: E) {
            if(e[1] == 0) { // abrir
                // cout<<e[0]<<' '<<last<<' '<<S.size()<<'\n';
                mxsum++;
                if(last != -1 and S.size() == 1) Ans[(*S.begin()).ss]++;
                if(S.size() == 0) comps++;
                S.insert({e[2], e[3]});
            }
            else {
                if(mxsum == 1) Ans[(*S.begin()).ss]--;
                if(S.size() == 1) mxsum = 0;
                last = (S.size() == 1? -1: 0);
                S.erase({e[2], e[3]});
            }
        }
        ll mx = -1;
        rep(i, n) mx = max(mx, Ans[i]);
        cout<<comps + mx<<'\n';
    }



    return 0;
}