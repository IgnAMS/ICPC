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

db eps = 1e-8;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<vi> A(n, vi(3)); // x, y, {P: 0, N: 1, -: 2}
    rep(i, n) {
        cin>>A[i][0]>>A[i][1];
        A[i][0] *= 2;
        char c; cin>>c; 
        if(c == 'P') A[i][2] = 0;
        if(c == 'N') A[i][2] = 1;
        if(c == '-') A[i][2] = 2;
        ll x = A[i][0], y = A[i][1];
        A[i][0] = x + y; 
        A[i][1] = y - x;
        // cout<<A[i][0]<<' '<<A[i][1]<<'\n';
    }
    // cout<<'\n';
    sort(A.begin(), A.end());
    ll mnN = 1e12;
    bool pos = 1;
    rep(i, n) {
        if(A[i][2] == 1) mnN = min(mnN, A[i][1]);
        if(A[i][2] == 2 and mnN <= A[i][1]) A[i][2] = 2;
        if(A[i][2] == 0 and mnN <= A[i][1]) pos = 0; 
    }

    rep(i, n) A[i][0] = -A[i][0];
    sort(A.begin(), A.end());
    ll mxP = -1e12, mxaux = -1e12;
    ll ans = 0;
    rep(i, n) {
        // cerr<<"procesando "<<A[i][0]<<' '<<A[i][1]<<'\n';
        // cerr<<mxaux<<' '<<mxP<<'\n';
        if(A[i][2] == 2) mxaux = max(mxaux, A[i][1]);
        else if(A[i][2] == 0 and A[i][1] <= mxP) continue;
        else if(A[i][2] == 0 and A[i][1] <= mxaux) {
            // cerr<<"entre aca?\n";
            mxP = mxaux;
            ans++;
        } 
        else if(A[i][2] == 0) { // A[i][1] > mxP
            // cerr<<"entre en un nuevo punto\n";
            mxP = A[i][1];
            ans++;
        }
    }
    if(pos) cout<<ans<<'\n';
    else cout<<"impossible\n";


    return 0;
}