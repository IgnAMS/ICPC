#pragma GCC optimize("Ofast")
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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll ans = 0;
        ii a, b, c; cin>>a.ff>>a.ss>>b.ff>>b.ss>>c.ff>>c.ss;
        if(a.ss == b.ss and a.ss > c.ss) ans += abs(a.ff - b.ff);
        if(a.ss == c.ss and a.ss > b.ss) ans += abs(a.ff - c.ff);
        if(b.ss == c.ss and b.ss > a.ss) ans += abs(b.ff - c.ff);
        cout<<ans<<'\n';

    }





    return 0;
}