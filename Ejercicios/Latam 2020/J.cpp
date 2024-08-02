#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<(int)b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++17 J.cpp -o a && a <input.txt> output.txt
//  g++ -O2 J.cpp && time ./a.out < input.txt > output.txt
#define ump unordered_map

ll I(ll b) { return b == 0? 0: b; }
ll J(ll b, ll k) { return k + 1; }


// 43046721
// 40000000
int Acc[40000000];
// 9^7 * 8
void upd(int i, int hash, int x, ll pot, vector<short>& B) {
    if(i == 8) {
        Acc[hash] += x;
    }
    else {
        rep(j, B[i] + 1) upd(i + 1, hash + pot * j, x, pot * 9, B);
    }
}

int query(int i, int hash, ll pot, vector<short>& B) {
    if(i == 8) return Acc[hash];
    return query(i + 1, hash + pot * B[i], pot * 9, B);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    vector<vector<short>> Q;
    rep(_, n) {
        char c; cin>>c; 
        if(c == 'C') {
            ll r; cin>>r;
            vector<short> B(8, 0);
            rep(j, r) {
                ll x; cin>>x; x--;
                B[x]++;
            }
            upd(0, 0, 1, 1, B);
            Q.push_back(B);
        }
        if(c == 'J') {
            ll r; cin>>r;
            vector<short> B(8, 0);
            rep(j, r) {
                ll x; cin>>x; x--;
                B[x]++;
            }
            ll ans = query(0, 0, 1, B);
            cout<<ans<<'\n';
        }
        if(c == 'D') {
            ll x; cin>>x; x--;
            vector<short> B = Q[x];
            upd(0, 0, -1, 1, B);
        }
    }

    return 0;
}