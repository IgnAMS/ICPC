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
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

ll m = 1e9 + 7;
ll bp(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    } 
    return res;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        ll g2;
        if(n <= 1) {
            cout<<1<<'\n';
            continue;
        }
        if(n % 3 == 0) g2 = 0;
        else if(n % 3 == 1) g2 = 2;
        else g2 = 1;
        ll g3 = (n - g2 * 2) / 3;
        cout<<(bp(2, g2) * bp(3, g3)) % m<<'\n';
    }





    return 0;
}