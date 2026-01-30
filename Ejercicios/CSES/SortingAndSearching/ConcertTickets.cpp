#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<map>
#include <algorithm>
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
// g++ -std=c++17 MissingCoinSum.cpp -o a && ./a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 ConcertTickets.cpp && time ./a.out <input.txt> output.txt


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    multiset<ll> S;
    rep(i, n) {
        int x; cin>>x;
        S.insert(x);
    }
    // S = {100}
    // x = {1}

    while(q--) {
        int x; cin>>x;
        auto it = S.upper_bound(x);
        if(it == S.begin()) {
            cout<<"-1\n";
        }
        else {
            int ans = *prev(it);
            cout<<ans<<"\n";
            S.erase(S.find(ans));
        }
        
        
    }
    


    
    return 0;
}