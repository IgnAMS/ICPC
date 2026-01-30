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
// g++ -O2 CollectingNumbersII.cpp && time ./a.out <input.txt> output.txt

const int INF = 1e9+1;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    vl A(n+2);
    int Index[n+3]; 
    repx(i, 1, n+1) {
        cin>>A[i];
        Index[A[i]] = i;
    }
    Index[n+1] = n+1;
    Index[0] = 0; 
    A[0] = 0, A[n+1] = n+1;
    
    ll curr = 1;
    ll ans = 1;
    repx(i, 1, n) {
        if(Index[i] > Index[i + 1]) {
            ans++;
        }
    }
    while(q--) {
        int a, b; cin>>a>>b;
        if(a > b) swap(a, b);
        ll dif = 0;
        if(Index[A[a]] > Index[A[a] + 1]) dif--;
        if(Index[A[a] - 1] > Index[A[a]]) dif--;
        if(Index[A[b]] > Index[A[b] + 1]) dif--;
        if(Index[A[b] - 1] > Index[A[b]]) dif--;
        if(A[a] == A[b]+1) dif++;
        dif *= -1;
        ll prev = dif;
        swap(Index[A[a]], Index[A[b]]);
        swap(A[a], A[b]);
        if(Index[A[a]] > Index[A[a] + 1]) dif--;
        if(Index[A[a] - 1] > Index[A[a]]) dif--;
        if(Index[A[b]] > Index[A[b] + 1]) dif--;
        if(Index[A[b] - 1] > Index[A[b]]) dif--;
        if(A[a] == A[b]+1) dif++;

        ans -= dif;
        cout<<ans<<"\n";
    }

    return 0;
}