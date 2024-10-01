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


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    ll suma = 0;
    vector<ll> A(n); rep(i, n) cin>>A[i];
    rep(i, n) suma += A[i];
    sort(A.begin(), A.end());
    ll m; cin>>m;
    rep(i, m){
        ll x, y; cin>>x>>y;
        auto low = lower_bound(A.begin(), A.end(), x);
        ll ans = 0;
        if(low == A.end()) { // No encontro
            ans += x - A.back();
            ans += max(0LL, y - suma + A.back());
        }
        else if(*low == x){
            ans += max(0LL, y - suma + x);
        }
        else{ // *low > x
            ans = max(0LL, y - suma + *low); 
            if(low != A.begin()){
                ans = min(ans, max(0LL, y - suma + *prev(low)) + x - *prev(low));
            }
        }
        cout<<ans<<'\n';
    } 
    return 0;
}