#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef double db;
#define ff first
#define ss second


ll dist(ii a, ii b){
    return (a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin>>n and n){
        vector<ii> P(n);
        rep(i, n) cin>>P[i].ff>>P[i].ss;
        ll ans = 0;
        rep(i, n){
            map<ll, ll> mapa;
            rep(j, n){
                ll a = dist(P[i], P[j]);
                if(!mapa.count(a)) mapa[a] = 0;
                mapa[a]++;
            }
            for(auto u: mapa) ans += u.ss * (u.ss - 1) / 2;

        }
        cout<<ans<<'\n';

    }

    return 0;
}