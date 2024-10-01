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
        int n; cin>>n;
        vl A(n + 1);
        A[0] = 1e18;
        rep(i, n) cin>>A[i + 1];
        ll C[n + 1];
        vl S = {0};
        vl Mn = {2 * A[0]};
        bool ok = true;
        ll acc = A[0];
        repx(i, 1, n + 1) {
            C[i] = acc;
            acc += A[i];
            while(A[S.back()] <= A[i]) {
                C[i] = min(C[i], C[S.back()]);
                Mn.pop_back();
                S.pop_back();
            }
            S.pb(i);
            Mn.pb(min(Mn.back(), A[i] + C[i]));
            if(acc > Mn.back()) ok = false;
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }


    return 0;
}