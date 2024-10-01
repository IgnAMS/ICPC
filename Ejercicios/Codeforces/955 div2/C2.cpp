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
    int t; cin>>t;
    while(t--) {
        ll n, l, r; cin>>n>>l>>r;
        vl A(n);
        vl Acc(n + 1, 0);
        rep(i, n) cin>>A[i];
        rep(i, n) Acc[i + 1] = Acc[i] + A[i];

        vl DP(n + 1, 0);
        rep(i, n) {
            DP[i + 1] = DP[i]; 
            if(Acc[i + 1] >= l) {
                ll l1 = 0, r1 = i + 1;
                // primer intervalo que es menor a l 
                while(l1 < r1) {
                    ll m = (l1 + r1) / 2;
                    if(Acc[i + 1] - Acc[m] < l) r1 = m;
                    else l1 = m + 1; 
                }
                // cout<<"i: "<<i<<", left: "<<l1 - 1<<", acc: "<<Acc[i + 1] - Acc[l1 - 1]<<'\n';
                ll val = Acc[i  +1] - Acc[l1 - 1];
                if(l1 - 1 >= 0 and l <= val and val <= r) DP[i + 1] = max(DP[i + 1], DP[l1 - 1] + 1);
                else if(l <= val and val <= r) DP[i + 1] = max(DP[i + 1], 1LL);
            }
            // cout<<DP[i + 1]<<'\n';
        }
        cout<<DP[n]<<'\n';
    }




    return 0;
}