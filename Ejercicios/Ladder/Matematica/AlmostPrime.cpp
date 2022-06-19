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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vi P;
    repx(i, 2, 3001) {
        bool p = 1;
        for(int j = 2; j <= sqrt(i); j++) if(i % j == 0) p = 0;
        if(p) P.push_back(i);
    }
    
    // 3000 * 3000
    int n; cin>>n;
    ll ans = 0;
    repx(i, 1, n + 1) {
        ll cont = 0;
        for(auto u: P) if(i % u == 0) cont++;
        if(cont == 2) ans++;
    }
    cout<<ans<<'\n';



    return 0;
}