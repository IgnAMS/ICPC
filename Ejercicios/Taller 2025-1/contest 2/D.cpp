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
// g++ -std=c++14 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll l = 1, r = n;
    while(l < r) {
        cout<<"? "<<l<<' '<<r<<endl;
        ll x; cin>>x;
        ll m = (l + r) / 2;
        if(x <= m) {
            if(l == m) {
                l = m + 1;
                continue;
            }
            cout<<"? "<<l<<' '<<m<<endl;
            ll y; cin>>y;

            // el elemento mayor esta en este segmento :o
            if(y == x) r = m;
            // el elemento mayor no esta en este segmento ;c
            else l = m + 1;
        }
        else {
            if(m + 1 == r) {
                r = m;
                continue;
            }
            cout<<"? "<<m + 1<<' '<<r<<endl;
            
            ll y; cin>>y;
            if(y == x) l = m + 1;
            else r = m;
        }
    }
    cout<<"! "<<l<<'\n';



    return 0;
}