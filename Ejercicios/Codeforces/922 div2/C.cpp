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
    ll t; cin>>t;
    while(t--) {
        ll a, b, x; cin>>a>>b>>x;
        if(a < b) swap(a, b); // a es el mayor
        ll ans = 0;
        ll curr = x;
        for(int i = 59; i >= 0; i--) {
            if(((a>>i) & 1) and !((b>>i) & 1) and (1LL<<i) <= curr and (a >= b + 2 * (1LL<<i))) {
                // cout<<"el bit "<<i<<" esta prendido en "<<a<<" y no en "<<b<<" y lo puedo anadir\n";
                a -= (1LL<<i);
                b += (1LL<<i);
                curr -= (1LL<<i);
                if(a < b) swap(a, b);
            }
        }
        cout<<(a ^ ans) - (b ^ ans)<<'\n';
    }





    return 0;
}