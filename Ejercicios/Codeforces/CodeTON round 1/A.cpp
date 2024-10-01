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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
    int n; cin>>n;
    vi A(n); rep(i, n) cin>>A[i];
    ll mxind = 0, mnind = 0;
    rep(i, n) {
        if(A[i] < A[mnind]) mnind = i;
        if(A[i] > A[mxind]) mxind = i;
    }
    cout<<mnind + 1<<' '<<mxind + 1<<'\n';
    }



    return 0;
}