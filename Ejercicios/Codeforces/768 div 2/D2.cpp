#pragma GCC optimize("Ofast")
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
    int t; cin>>t;
    while(t--) {
        int n, k; cin>>n>>k;
        vi A(n); rep(i, n) cin>>A[i];
        vi F(n + 1, 0); rep(i, n) F[A[i]]++;
        ll x = 1, y = 1, r = 1;
        ll ans = 1e6;
        ll acc = F[1];
        repx(l, 1, n + 1) {
            acc -= F[l - 1];
            while(r + 1 <= n and acc < (n + k + 1) / 2) acc += F[++r];
            if(acc >= (n + k + 1) / 2 and r - l < ans) {
                ans = r - l, x = l, y = r;
            }
        }
        ll in_range = 0;
        vector<ii> S;
        ll l = 0;
        rep(i, n) {
            if(x <= A[i] and A[i] <= y) in_range++;
            else in_range--;
            if(in_range > 0 and S.size() < k - 1) {
                S.push_back({l + 1, i + 1});
                l = i + 1;
                in_range = 0;
            }
        }
        S.push_back({l + 1, n});
        
        cout<<x<<' '<<y<<'\n';
        for(auto u: S) cout<<u.ff<<' '<<u.ss<<'\n';
    }
    




    return 0;
}