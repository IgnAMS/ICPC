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
    ll n, s; cin>>n>>s;
    vl A(n); rep(i, n) cin>>A[i];
    sort(A.begin(), A.end());
    ll ans = 0;
    if(A[n / 2] <= s) {
        // A[n / 2] <= s -> debo hacer los valores de la derecha mas grandes
        repx(i, n / 2, n) ans += max(0LL, s - A[i]); 
    }
    else {
        // A[n / 2] > s -> debo hacer los elementos de la izquierda mas chicos
        repx(i, 0, n / 2 + 1) ans += max(0LL, A[i] - s);
    }
    cout<<ans<<'\n';
    

    return 0;
}