#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
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
// g++ -O2 TrafficLights.cpp && time ./a.out <input.txt> output.txt

const int INF = 1e9+1;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int L, q; cin>>L>>q;
    set<ll> P = {0, L};
    multiset<ll> S = {L};
    while(q--) {
        int x; cin>>x;
        int left = *prev(P.upper_bound(x));
        int right = *P.upper_bound(x);
        P.insert(x);
        S.erase(S.find(right - left));
        S.insert(x - left);
        S.insert(right - x);
        cout<<*S.rbegin()<<" ";
    }
    cout<<"\n";

    return 0;
}