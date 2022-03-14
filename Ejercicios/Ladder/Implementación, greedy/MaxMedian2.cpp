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
    int n, k; cin>>n>>k;
    vi A(n); rep(i, n) cin>>A[i];
    int l = 1, r = n + 1;
    while(l < r) {
        vi F(n + 1, 0);
        int m = (l + r) / 2;
        rep(i, n) F[i + 1] = F[i] + (A[i] < m? -1: 1);
        bool oc = 0;
        ll mx = F[k], mn = 0;
        repx(i, k + 1, n + 1) {
            mn = min(mn, F[i - k]);
            mx = max(mx, F[i] - mn);
        }
        if(mx > 0) l = m + 1, oc = 1;
        else r = m;
        cerr<<l<<' '<<r<<' '<<m<<' '<<oc<<'\n';
        
    }
    cout<<l - 1<<'\n';

    return 0;
}