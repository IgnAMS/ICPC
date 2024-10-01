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
    ll A[6]; 
    rep(i, 6) cin>>A[i];
    ll ans = 0, x = 2 * A[5] + 1;
    ll prev = 0;
    // cout<<x<<'\n';
    rep(i, min(A[0], A[4])) {
        ans += x, x += 2;
        // cout<<x<<'\n';   
        // cout<<x<<' '<<'\n';
    }
    x = 2 * A[2] + 1;
    rep(i, min(A[1], A[3])) {
        ans += x, x += 2;
    }
    ans += (x - 1) * (max(A[3], A[1]) - min(A[1], A[3]));
    cout<<ans<<'\n';



    return 0;
}