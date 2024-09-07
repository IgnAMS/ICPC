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
    ll n, x; cin>>n>>x;
    set<array<ll, 3>> S;
    vl A(n);
    rep(i, n) cin>>A[i];
    
    rep(i, n) {
        repx(j, i + 1, n) {
            auto it = S.lower_bound({x - A[i] - A[j], j + 1, 0});
            if(it == S.end()) continue;
            if((*it)[0] == x - A[i] - A[j]) {
                cout<<i + 1<<' '<<j + 1<<' '<<(*it)[1] + 1<<' '<<(*it)[2] + 1<<'\n';
                return 0;
            }
        }
        repx(j, i + 1, n) S.insert({A[i] + A[j], j, i});
    }


    cout<<"IMPOSSIBLE\n";


    return 0;
}