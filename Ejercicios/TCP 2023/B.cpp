#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
    ll n; cin>>n;
    vl A(n); rep(i, n) A[i] = i + 1;
    map<vl, int> D;
    map<vl, vl> P; P[A] = {-1};
    queue<vl> Q; Q.push(A);

    D[A] = 0;
    while(!Q.empty()) {
        // Defino un punto medio
        auto vec = Q.front(); Q.pop();
        if(D[vec] == 1) continue;
        repx(i, 1, n) { 
            ll l = i, r = n - i;
            // Secuencia de 0s y 1s 
            rep(mask, (1<<(2*min(l, r)))) {
                ll li = 0, ri = 0;
                vl N;
                rep(j, (2*min(l, r))) {
                    cout<<bool(mask & (1<<j))<<' ';
                    if(li < l and mask & (1<<j)) {
                        N.pb(vec[li]);
                        li++;
                    }
                    else if(ri < r and !(mask & (1<<j))) {
                        N.pb(vec[i + ri]);
                        ri++;
                    }
                }
                vl vec1 = N;
                vl vec2;
                cout<<'\n';
                cout<<li<<' '<<l<<' '<<ri<<' '<<r<<'\n';
                while(li < l) {
                    vec1.pb(vec[li]);
                    vec2.pb(vec[li]);
                    li++;
                }
                while(ri < r) {
                    vec1.pb(vec[i + ri]);
                    vec2.pb(vec[i + ri]);
                    ri++;
                }
                for(auto u: N) vec2.pb(u);
                cout<<"N: "; for(auto u: N) cout<<u<<' '; cout<<'\n';
                cout<<"vec1: "; for(auto u: vec1) cout<<u<<' '; cout<<'\n';
                cout<<"vec2: "; for(auto u: vec2) cout<<u<<' '; cout<<'\n';
                cout<<'\n';
                if(!D.count(vec1)) {
                    D[vec1] = D[vec] + 1;
                    P[vec1] = vec;
                    Q.push(vec1);
                }
                if(!D.count(vec2)) {
                    D[vec2] = D[vec] + 1;
                    P[vec2] = vec;
                    Q.push(vec2);
                }
            }
        }
    }
    cerr<<"estoy vivo\n";
    for(auto [vec, d] : D) {
        for(auto u: vec) cout<<u<<' '; cout<<'\n';
        cout<<d<<"\n\n";
    }

    vl B(n); rep(i, n) cin>>B[i];
    while(B[0] != -1 and P.count(B)) {
        for(auto u: B) cout<<u<<' '; cout<<'\n';
        B = P[B];
    }




    return 0;
}