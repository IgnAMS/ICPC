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
    int n = 3;
    ll M[] = {3, 5, 6};
    repx(i1, 1, 10) repx(i2, 1, 10) repx(j1, 1, 10) repx(j2, 1, 10) repx(k1, 1, 10) repx(k2, 1, 10) {
        ll W[] = {i1, j1, k1};
        ll V[] = {i2, j2, k2};
        if()
        for(int mask: M) {
            ll cont = 0, w = 0, v = 0;
            vl A;
            rep(i, n) if((1<<i) & mask) {
                A.pb(i);
                cont++;
                cout<<"anado a "<<i<<" con: ";
                cout<<W[i]<<' '<<V[i]<<'\n';
                w += W[i], v += V[i];
            }
            if(cont != 2) continue;
            cout<<"respuesta\n";
            cout<<db(v) / db(w)<<'\n';
            
        }
        cout<<"\n\n";
    }



    return 0;
}