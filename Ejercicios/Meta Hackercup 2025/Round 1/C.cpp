#pragma GCC optimize("Ofast")
#include<vector>
#include<map>
#include<iostream>
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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txtß



void solve(int caso) {
    int n; cin>>n;
    vl A(n); 
    map<ll, ll> cont;
    cont[0] = 1;
    ll ans = 0;
    ll curr = 0;
    rep(i, n) {
        cin>>A[i];
        curr ^= A[i];
        if(cont.count(curr)) {
            ans += 1LL * (i+1) * (i+2)/2 - (cont[curr] * (cont[curr] + 1)) / 2;
            cont[curr] += + 1;
        }
        else {
            cont[curr] = 1;
            ans += 1LL * (i+1) * (i+2) / 2;
        }
    }


    cout<<"Case #"<<caso+1<<": "<<ans<<"\n";    
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; 
    rep(i, t) solve(i);
    return 0;
}