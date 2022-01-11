#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

ll f(ll m){
    if(m <= 100) return m * 2;
    else if(m <= 10000) return 100 * 2 + (m - 100) * 3;
    else if(m <= 1000000) return 100 * 2 + 9900 * 3 + (m - 10000) * 5;
    return 100 * 2 + 9900 * 3 + 990000 * 5 + (m - 1000000) * 7;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll a, b;
    while(cin>>a>>b and a){
        ll l = 0, r = 1e10; // busco cuantos billetes paga el primero
        while(l < r){
            ll m = (l + r) / 2;
            ll x = f(m);
            if(x < a) l = m + 1;
            else r = m;
        }
        // cout<<l<<": "<<f(l)<<'\n';
        ll l2 = 0, r2 = l/2; // rango de x (el menor de los dos)
        while(l2 < r2) {
            ll m = (l2 + r2) / 2;
            ll fx = f(m), fy = f(l - m);
            if(fy - fx > b) l2 = m + 1; // si la diferencia es pequeña aumento x?
            else r2 = m;
        }
        // cout<<l2<<": "<<f(l2)<<", "<<l - l2<<": "<<f(l - l2)<<'\n';
        // cout<<f(l - l2) - f(l2)<<'\n';
        cout<<f(l2)<<'\n';
        
    }


    return 0;
}