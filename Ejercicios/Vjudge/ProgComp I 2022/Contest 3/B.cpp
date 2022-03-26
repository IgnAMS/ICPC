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
    int n, q; cin>>n>>q;
    vi A(n); rep(i, n) cin>>A[i];
    rep(i, q) {
        ll x; cin>>x;
        auto it = upper_bound(A.begin(), A.end(), x);
        it = it == A.begin()? it: prev(it);
        cout<<(x == *it? it - A.begin(): -1)<<'\n';
    }





    return 0;
}