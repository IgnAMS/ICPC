#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

// find (x, y) such that Ax + By = gcd(A, B), and |Ax|, |By| <= AB/gcd(A, B)
pll euclid(ll A, ll B){
    if (!B) return {1, 0};
    pll p = euclid(B, A % B);
    return {p.ss, p.ff - (A / B) * p.ss};
}

// find (x, y)'s such that Ax + By = R where R is multiplle of gcd(A, B);
pair<pll, pll> diophantine(ll A, ll B, ll R)
{
    ll g = __gcd(A, B), x, y; A /= g, B /= g, R /= g;
    tie(x, y) = euclid(A, B); x *= R, y *= R;
    if(A * x + B * y != R) return {{-1, -1}, {-1, -1}};
    // assert(A * x + B * y == R);
    return {{x, y}, {-B, A}}; // solutions: p+t*ans.snd
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        ll a, b, x; cin>>a>>b>>x;
        if(x > max(a, b) or x % __gcd(a, b) != 0) { cout<<"NO\n"; continue; }
        pair<pll, pll> aux = diophantine(a, b, x);
        if(aux.ss.ss == -1) {
            cout<<"NO\n"; continue;
        }
        cout<<"YES\n";

    }


    return 0;
}