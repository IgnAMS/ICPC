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
    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];
    
    
    ll ans = 0, sobra = 0;
    rep(i, n) {
        if(sobra >= A[i] / 2) sobra -= A[i] / 2, ans += A[i] / 2, sobra += A[i] % 2;
        else {
            // consumo todo lo que sobra
            ans += sobra;
            A[i] -= 2 * sobra;
            sobra = 0;

            ans += (A[i] / 3);
            A[i] %= 3;
            sobra += A[i];
        }
        // cout<<ans<<' '<<A[i]<<' '<<sobra<<'\n';
    }
    cout<<ans<<'\n';



    return 0;
}