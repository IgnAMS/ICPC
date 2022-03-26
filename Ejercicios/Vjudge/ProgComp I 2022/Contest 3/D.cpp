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
    ll n, l; cin>>n>>l;
    vi A(n); rep(i, n) cin>>A[i];
    sort(A.begin(), A.end()); 
    db ans = 0;
    if(A[0] != 0) ans = max(ans, 1.0 * A[0]);
    if(A[n - 1] != l) ans = max(ans, 1.0 * (l - A[n - 1]));
    rep(i, n - 1) ans = max(ans, db(A[i + 1] - A[i]) / 2.0);
    cout<<setprecision(11)<<fixed<<ans<<'\n';



    return 0;
}