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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vi A(n); rep(i, n) cin>>A[i];
        vi MxL(n), MxR(n), MnL(n), MnR(n);
        int mnid = 0, mxid = 0;
        rep(i, n) {
            if(A[i] < A[mnid]) mnid = i;
            if(A[i] > A[mxid]) mxid = i;
            MxL[i] = mxid;
            MnL[i] = mnid;
        }
        mnid = n - 1, mxid = n - 1;
        for(int i = n - 1; i >= 0; i--) {
            if(A[i] < A[mnid]) mnid = i;
            if(A[i] > A[mxid]) mxid = i;
            MxR[i] = mxid;
            MnR[i] = mnid;
        }
        ll pos1, posn;
        rep(i, n) {
            if(A[i] == 1) pos1 = i;
            if(A[i] == n) posn = i;
        }

        ll ans = 0;
        if(pos1 < posn) {
            bool up = 1;
            while(pos1 > 0) {
                if(up) pos1 = MxL[pos1];
                else pos1 = MnL[pos1];
                up = !up;
                ans++;
            }
            up = 0;
            while(posn < n - 1) {
                if(up) posn = MxR[posn];
                else posn = MnR[posn];
                up = !up;
                ans++;
            }
        }
        else {
            bool up = 1;
            while(pos1 < n - 1) {
                if(up) pos1 = MxR[pos1];
                else pos1 = MnR[pos1];
                up = !up;
                ans++;
            }
            up = 0;
            while(posn > 0) {
                if(up) posn = MxL[posn];
                else posn = MnL[posn];
                up = !up;
                ans++;
            }
        }
        cout<<ans + (n != 1)<<'\n';
        // cerr<<"termine la iteracion\n";
    }


    return 0;
}