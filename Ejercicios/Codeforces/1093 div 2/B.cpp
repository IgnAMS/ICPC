#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include<algorithm>
#include<numeric>
#include <cmath>
#include<set>
#include<array>
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
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -std=c++17 -O2 B.cpp && time ./a.out <input.txt> output.txt

const int mxN = 2e5+5;
int n, m;
int A[mxN];


void solve() {
    cin>>n>>m;
    bool pos = 1;
    int last = -1;
    int cont = 0;
    rep(i, n) {
        cin>>A[i];
        if(A[i] == last) cont++;
        else cont = 1;
        if(cont == m) pos = 0;
        last = A[i];
    }
    cout<<(pos? "YES" : "NO")<<"\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
