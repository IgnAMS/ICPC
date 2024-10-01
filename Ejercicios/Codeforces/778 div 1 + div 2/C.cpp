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



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vi A(n); rep(i, n) cin>>A[i];
        ll suma = 0; rep(i, n) suma += A[i];
        sort(A.begin(), A.end());
        map<ll, ll> mp;
        rep(i, n){
            if(!mp.count(A[i])) mp[A[i]] = 0;
            mp[A[i]]++;
        }
        // cout<<suma<<'\n';
        priority_queue<ll, vi> pq;
        pq.push(suma);
        map<ll, ll> F; F[suma] = 1;
        ll cont = 0;
        while(!pq.empty()) {
            ll u = pq.top(); pq.pop();
            // cerr<<"estoy explorando a "<<u<<'\n';
            if(mp.count(u)) {
                ll x = F[u];
                F[u] -= min(mp[u], x);
                mp[u] -= min(mp[u], x); // le saco todo lo que puedo
                // cerr<<u<<' '<<F[u]<<'\n';
            }
            // cerr<<u / 2<<' '<<(u + 1) / 2<<' '<<u<<' '<<F[u]<<'\n';
            if(!F.count(u / 2) and u != 1 and F[u]) { 
                F[u / 2] = 0;
                pq.push(u / 2);
            }
            if(!F.count((u + 1) / 2) and u != 1 and F[u]) {
                F[(u + 1) / 2] = 0;
                pq.push((u + 1) / 2);
            }
            if(u != 1 and F[u]) F[u / 2] += F[u], F[(u + 1) / 2] += F[u];
        }
        bool pos = 1;
        for(auto u: mp) if(u.ss) pos = 0;
        cout<<(pos? "YES": "NO")<<'\n';  

        // cerr<<"termine el caso "<<suma<<'\n';
    }


    return 0;
}