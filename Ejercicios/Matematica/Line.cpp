#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
typedef pair<ll, ll> pll;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt

pll euclid(ll A, ll B){
    if (!B) return {1, 0};
    pll p = euclid(B, A % B);
    return {p.ss, p.ff - (A / B) * p.ss};
}

pair<pll, pll> diophantine(ll A, ll B, ll R){
    ll g = __gcd(A, B), x, y; A /= g, B /= g, R /= g;
    tie(x, y) = euclid(A, B); x *= R, y *= R;
    assert(A * x + B * y == R);
    return {{x, y}, {-B, A}}; // solutions: p+t*ans.snd
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll a, b, c; cin>>a>>b>>c;
    if(a == 0) {
        if(c % b != 0) cout<<"-1\n";
        else cout<<0<<' '<<-c/b<<'\n';
    }
    else if(b == 0){
        if(c % a != 0) cout<<"-1\n";
        else cout<<-c/a<<' '<<0<<'\n';
    }
    else{
        if(c % __gcd(a, b) != 0) cout<<"-1\n";
        else cout<<diophantine(a, b, -c).ff.ff<<' '<<diophantine(a, b, -c).ff.ss<<'\n';
    }


    return 0;
}