#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<char> A(n), B(n);
        rep(i, n) cin>>A[i];
        rep(i, n) cin>>B[i];
        rep(i, n) if(A[i] == 'G') A[i] = 'B';
        rep(i, n) if(B[i] == 'G') B[i] = 'B';
        bool oc = 1;
        rep(i, n) if(A[i] != B[i]) oc = 0;
        if(!oc) {
            cout<<"NO\n";
        }
        else cout<<"YES\n";
    }


    return 0;
}