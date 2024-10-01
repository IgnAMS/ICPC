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
        ll n, x; cin>>n>>x;
        vi A(n); rep(i, n) cin>>A[i];
        sort(A.begin(), A.end());
        vi Acc(n + 1, 0); rep(i, n) Acc[i + 1] = Acc[i] + A[i];
        ll ind = 0, mx = 0, aux = 0;
        rep(i, n + 1) if(Acc[i] <= x) ind = i, mx = Acc[i];
        ll ans = 0;
        while(ind > 0) {
            ll t = (x - Acc[ind] - ind * aux) / ind;
            // cout<<x<<' '<<ind<<' '<<Acc[ind] + ind * aux<<' '<<t<<'\n';
            ans += (t + 1) * ind;
            aux += t + 1;
            while(ind > 0 and Acc[ind] + ind * aux > x) ind--;
        }
        cout<<ans<<'\n';
    }





    return 0;
}