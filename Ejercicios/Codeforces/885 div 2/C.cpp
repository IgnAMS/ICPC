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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        ll A[n]; rep(i, n) cin>>A[i];
        ll B[n]; rep(i, n) cin>>B[i];

        vl C(n, 0);
        vl Z(n, 0);
        rep(i, n) {
            if(A[i] == B[i]) C[i] = 1;
            if(A[i] == B[i] and A[i] == 0) Z[i] = 1;
            if(A[i] != B[i]) {
                if(A[i] == 0) {
                    C[i] = 2;
                    continue;
                }
                if(B[i] == 0) {
                    C[i] = 3;
                    continue;
                }

                ll cont = 0;
                ll x = A[i], y = B[i];

                // cout<<x<<' '<<y<<'\n';
                while(x < y and x != 0) {
                    cont++;
                    ll prevy = y;
                    y = abs(x - y);
                    x = prevy;
                    // cout<<x<<' '<<y<<'\n';
                }

                while(x != 0) {
                    ll curr = x / y;
                    cont += curr + (curr / 2);
                    // cout<<"anado "<<curr + (curr / 2) <<" para "<<x<<' '<<y<<'\n';
                    x = x % y;
                    if(x == 0) {
                        if(curr % 2 == 0) cont--;
                        break;
                    }

                    if(curr % 2 == 0) {
                        ll prevy = y;
                        y = y - x;
                        x = prevy;
                        cont++;
                    }
                    else swap(x, y);

                }
                C[i] = cont;
            }
        }
        ll res = -1;
        bool pos = 1;
        rep(i, n) {
            // cout<<Z[i]<<' '<<res<<' '<<(C[i] % 3)<<'\n';
            if(!Z[i] and res == -1) res =  C[i] % 3;
            if(!Z[i] and res != -1 and (C[i] % 3) != res) pos = 0;
        }
        if(!pos) cout<<"NO\n";
        else cout<<"YES\n";
        // rep(i, n) cout<<C[i]<<' '; cout<<'\n';
        // cout<<'\n';

    }


    return 0;
}