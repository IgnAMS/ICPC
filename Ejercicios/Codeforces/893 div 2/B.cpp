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
        int n, m, d; cin>>n>>m>>d;
        vl A(m); rep(i, m) cin>>A[i];
        ll curr = 0;
        ll last = 1;
        if(A[0] != 1) curr++; last = 1;
        rep(i, m) {
            curr += (A[i] - last - 1) / d + 1;
            last = A[i];
        }
        curr += (n - last) / d;
        // cout<<curr<<'\n';

        ll best = curr, nmin = 0;
        rep(i, m) {
            ll newcurr = curr;
            if(A[i] != 1) newcurr--;
            newcurr -= (i == 0? (A[i] - 1 - 1) / d: (A[i] - A[i - 1] - 1) / d);
            newcurr -= (i == m - 1? (n - A[i]) / d: (A[i + 1] - A[i] - 1) / d);
            if(i == 0) newcurr += (A[i + 1] - 1 - 1) / d;
            else if(i + 1 < m) newcurr += (A[i + 1] - A[i - 1] - 1) / d;
            else if(i == m - 1) newcurr += (n - A[i - 1]) / d;
            if(newcurr < best) {
                best = newcurr;
                nmin = 1;
            }
            else if(newcurr == best) nmin++;
            // cout<<newcurr<<'\n';
        }

        cout<<best<<' '<<nmin<<'\n';
    }
    
    return 0;
}