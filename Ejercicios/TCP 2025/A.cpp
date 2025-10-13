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

const int offset = 100;
const int mxN = 3e6 + offset + 1;
int acc[mxN / offset];
vector<bool> actv(mxN, false);


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    int aux;
    rep(i, n) {
        cin>>aux;
        actv[aux] = 1;
    }
    repx(i, 1, int(3e6 / offset + 1)) {
        if(i) acc[i] = acc[i - 1];
        repx(j, (i - 1) * offset, i * offset) {
            acc[i] += actv[j];
        }
    }
    int ans = 0;
    rep(_, q) {
        cin>>aux;
        ans = acc[aux / offset];
        // cout<<aux / 10<<' '<<acc[aux / 10]<<'\n';
        for(int i = (aux / offset) * offset; i < aux; i++) {
            ans += actv[i];
        }
        cout<<ans<<'\n';
    }

    return 0;
}