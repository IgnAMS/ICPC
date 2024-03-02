#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
    ll h, l; cin>>h>>l;
    // a + h == sqrt(l^2 + a^2) ->  a^2 + 2ah + h^2 == l^2 + a^2
    //                          ->  2ah + h^2  == l^2
    //                          -> a == (l^2 - h^2) / 2h 
    cout<<setprecision(8)<<fixed<<db(l * l - h * h) / (2. * h)<<'\n';


    return 0;
}