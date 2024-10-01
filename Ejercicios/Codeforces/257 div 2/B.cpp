#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int, int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll x, y; cin>>x>>y;
    vi A = {x, y};
    rep(i, 4) A.push_back(A[i + 1] - A[i]);
    ll n; cin>>n;
    ll mod = 1e9 + 7;
    cout<<(A[(n - 1) % 6] + 5 * mod) % mod; 


    return 0;
}