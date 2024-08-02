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
    int n, m, k; cin>>n>>m>>k;
    string S[n];
    rep(i, n) cin>>S[i];

    unordered_set<ll> searched; searched.reserve(20);
    unordered_set<ll> time_k;
    time_k.reserve(n);
     

    srand(time(0));


    // 200 * n * m ~ 200 * 10^7
    rep(_, 200) {
        ll x = rand() % n;
        while(searched.count(x)) {
            x = rand() % n;
        }
        searched.insert(x);
        
        ll dists[n];
        rep(i, n) if(i != x) {
            
        }
    }





    return 0;
}