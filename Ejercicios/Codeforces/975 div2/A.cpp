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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        ll A[n], suma1 = 0, mx1 = 0, suma2 = 0, mx2 = 0;
        rep(i, n) {
            cin>>A[i];
            if(i & 1) suma1 += A[i], mx1 = max(mx1, A[i]);
            else suma2 += A[i], mx2 = max(mx2, A[i]);
        }
        cout<<max(mx1 + n / 2, mx2 + (n + 1) / 2)<<'\n';
    }


    return 0;
}