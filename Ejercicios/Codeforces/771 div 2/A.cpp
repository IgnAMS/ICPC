#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vi A(n); rep(i, n) cin>>A[i];
        ll f = -1, rev = -1;
        rep(i, n) {
            if(f == -1 and A[i] != i + 1) f = i;
            if(A[i] == f + 1) rev = i;
        }
        // cout<<f<<' '<<rev<<'\n';
        vi B(n); rep(i, n) B[i] = i + 1;
        if(f != -1) {
            rep(i, f) B[i] = A[i];
            rep(i, rev + 1 - f) B[f + i] = A[rev - i];
            repx(i, rev + 1, n) B[i] = A[i];  
        }
        rep(i, n) cout<<B[i]<<' '; cout<<'\n';
    }





    return 0;
}