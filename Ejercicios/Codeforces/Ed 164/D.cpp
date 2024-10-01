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
    int n; cin>>n;
    ll A[n];
    rep(i, n) cin>>A[i];

    vector<vl> DP(n + 1, vl(2, 0));
    vector<vl> DP2(n + 1, vl(2, 0));
    if(A[0] % 2 == 0) {
        DP[A[0] / 2][0] = A[0] / 2;
    }
    else {
        DP[A[0] / 2 + 1][1] = A[0] / 2 + 1;
    }

    repx(i, 1, n) {
        repx(j, n + 1) rep(b, 2) {
            if(A[i] % 2 == 0) {
                DP2[j + A[i] / 2][b] += DP[j][b] + 
            }
        }
    }


    return 0;
}