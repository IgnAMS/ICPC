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
        int mxX = 0, mnY = 0, mxY = 0, mnX = 0;
        rep(i, n) {
            int x, y; cin>>x>>y;
            mxX = max(mxX, x);
            mnX = min(mnX, x);
            mxY = max(mxY, y);
            mnY = min(mnY, y);
        }
        cout<<2 * (mxX - mnX + mxY - mnY)<<'\n';
    }


    return 0;
}