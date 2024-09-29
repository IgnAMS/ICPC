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

int X[6];
ll A[6][6];
ll ans = 0, curr = 0;

void backtrack(int i) {
    if(i == 6) {
        ans = max(ans, curr);
        return;
    }
    rep(j, 6) if(X[j] == 0) {
        X[j] = 1;
        curr += A[i][j];
        backtrack(i + 1);
        X[j] = 0;
        curr -= A[i][j];
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // 6^6 messi
    rep(i, 6) rep(j, 6) cin>>A[i][j];    
    backtrack(0);
    cout<<ans<<'\n';


    return 0;
}