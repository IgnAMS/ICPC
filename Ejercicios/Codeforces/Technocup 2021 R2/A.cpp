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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t; cin>>t;
    while(t--) {
        ll n, m, r, c; cin>>n>>m>>r>>c;
        ii A[] = {{1, 1}, {n, 1}, {1, m}, {n, m}};
        ll ans = 0;
        rep(i, 4){
            ans = max(ans, abs(r - A[i].ff) + abs(c - A[i].ss));
        }
        cout<<ans<<'\n';
    }





    return 0;
}