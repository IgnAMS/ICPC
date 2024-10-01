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
    int t; cin>>t;
    while(t--) {
        ll x, k, y; cin>>x>>y>>k;
        x += 1, k -= 1;
        ll next = ((x + y - 1) / y) * y;
        while(x >= y and x + k >= next) { 
            k -= next - x;
            x = next;
            while(x % y == 0) x /= y;
            // Despues de esto, x ya no es multiplo de y por lo que requiere al menos un paso de k
            next = ((x + y - 1) / y) * y;
        }
        // si no lo alcanzo, entonces imprimo la respuesta
        if(x + k < next) cout<<x + k<<'\n';
        // Si lo alcanzo, entonces hago modulo
        else cout<<((x + k - 1) % (y - 1) + 1)<<'\n';
    }

    return 0;
}