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
    int num = (1 << 30) - 1;
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vi A(n), B(n, 0); rep(i, n) cin>>A[i];
        repx(i, 1, n) {
            B[i] = (num ^ A[i]) & (A[i - 1] | B[i - 1]);
        }
        rep(i, n) cout<<B[i]<<' '; cout<<'\n';
        
    }





    return 0;
}