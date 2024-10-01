#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vl A(n); rep(i, n) cin>>A[i];
        vl Acc(n + 1, 0); 
        for(int i = n - 1; i >= 0; i--) Acc[i] = Acc[i + 1] + A[i];
        // rep(i, n) cout<<Acc[i]<<' '; cout<<'\n';
        ll k = 1;
        ll last = -1;
        ll ans = 0;
        rep(i, n) {
            if(Acc[i + 1] >= 0) {
                // cout<<"divido en "<<i<<'\n';
                // cout<<(Acc[last + 1] - Acc[i + 1])<<'\n';
                ans += k * (Acc[last + 1] - Acc[i + 1]);
                last = i;
                k++;
            }
        }
        cout<<ans<<'\n';

    }


    return 0;
}