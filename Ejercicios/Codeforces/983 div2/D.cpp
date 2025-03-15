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
// g++ -std=c++11 D.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        ll first = n + 1;
        set<ll> X = {1};
        ll P[n], L[n + 1];
        L[1] = 1;
        P[1] = 0;
        for(int i = 2; i < n; i++) {
            cout<<"? 1 "<<i<<endl;
            ll r; cin>>r;
            if(r == 0) {
                P[i] = 1;
                L[1] = i;
                first = i;
                break;
            }
            P[i] = 0;
            L[i] = i;
            X.insert(i);
        }

        vl Elim;
        X.erase(1);
        first++;
        bool xd = 1;
        while(first < n) {
            for(auto u: X) {
                cout<<"? "<<u<<' '<<first<<endl;
                ll r; cin>>r;
                if(r == 0) {
                    P[first] = L[u];
                    L[u] = first;
                    first++;
                    if(first >= n) break;
                }
                else Elim.pb(u);
            }
            // cout<<"termine el ciclo y debo eliminar a"<<endl;
            // for(auto u: Elim) cout<<u<<' '; cout<<endl;
            for(auto u: Elim) X.erase(u);
            if(!Elim.empty() and Elim[0] == 1) xd = 0;
            Elim.clear();
            if(xd) X.insert(1);
        }
        cout<<"! "; repx(u, 1, n) cout<<P[u]<<' '; cout<<endl;
    }

    return 0;
}