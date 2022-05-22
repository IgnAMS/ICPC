#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int n;
vi T, A, W; 
ll DP[1001][22][81];

ll dp(int ind, int t, int a) {
    t = max(0, t), a = max(0, a);
    if(t == 0 and a == 0) return 0;
    if(ind == n)
    if(DP[ind][t][a] != -1) return DP[ind][t][a];
    
    return DP[ind]
}






int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int t, a; cin>>t>>a;
        cin>>n;
        A.resize(n); T.resize(n); W.resize(n);
        rep(i, n) cin>>T[i]>>A[i]>>W[i];

    }

    return 0;
}