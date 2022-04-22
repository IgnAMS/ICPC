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
//  g++ -O2 JobAllocator.cpp && time ./a.out < input.txt > output.txt


ll I(ll b) { return b == 0? 0: b; }
ll J(ll b, ll k) { return k + 1; }

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // cout<<8 * 8 * 8 * 8 * 8 * 8 * 8 * 8<<'\n'; 
    ll A[8][8][8][8][8][8][8][8];
    rep(i1, 8) rep(i2, 8) rep(i3, 8) rep(i4, 8) rep(i5, 8) rep(i6, 8) rep(i7, 8) rep(i8, 8)
        A[i1][i2][i3][i4][i5][i6][i7][i8] = 0;
    
    int n, k; cin>>n>>k;
    vector<vi> Q;
    // cerr<<"llegue hasta aca???\n";
    rep(i, n) {
        char c; cin>>c; 
        // cerr<<"c: "<<c<<'\n'; return 0;
        if(c == 'C') {
            cerr<<"deberia entrar aca\n"; return 0;
            ll r; cin>>r;
            vi B(8, 0); 
            cerr<<"me caigo aca???\n"; return 0;
            rep(j, r) {
                ll x; cin>>x; x--;
                B[x]++;
            }
            // rep(i, 8) cout<<B[i]<<' '; cout<<"\nLe aumento 1\n";
            A[B[0]][B[1]][B[2]][B[3]][B[4]][B[5]][B[6]][B[7]]++;
            Q.push_back(B);
        }
        if(c == 'J') {
            ll r; cin>>r;
            vi B(8, 0);
            rep(j, r) {
                ll x; cin>>x; x--;
                B[x]++;
            }
            // rep(j, 8) cout<<B[j]<<' '; cout<<"\nHago la query\n";
            ll x = 8;
            ll ans = 0;
            repx(i0, B[0], 8) 
                repx(i1, B[1], 8 - i0) 
                    repx(i2, B[2], 8 - i0 - i1) 
                        repx(i3, B[3], 8 - i0 - i1 - i2) 
                            repx(i4, B[4], 8 - i0 - i1 - i2 - i3)
                                repx(i5, B[5], 8 - i0 - i1 - i2 - i3 - i4)
                                    repx(i6, B[6], 8 - i0 - i1 - i2 - i3 - i4 - i5)
                                        repx(i7, B[7], 8 - i0 - i1 - i2 - i3 - i4 - i5 - i6)
                                            ans += A[i0][i1][i2][i3][i4][i5][i6][i7];
            cout<<ans<<'\n';
        }
        if(c == 'D') {
            ll x; cin>>x; x--;
            A[Q[x][0]][Q[x][1]][Q[x][2]][Q[x][3]][Q[x][4]][Q[x][5]][Q[x][6]][Q[x][7]]--;
        }
    }



    return 0;
}