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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll a, b, x, r; cin>>a>>b>>x>>r;
        if(a > b) swap(a, b);
        // cout<<x - r<<' '<<x<<' '<<x + r<<'\n';
        // cout<<a<<' '<<b<<'\n';
        if(x - r <= a) {
            if(x + r >= b) cout<<0<<'\n';
            else if(x + r >= a) cout<<b - (x + r)<<'\n';
            else cout<<b - a<<'\n';
        }
        else { // x - r > a
            if(x - r > b) cout<<b - a<<'\n';
            else if(x + r > b) cout<<x - r - a<<'\n';
            else if(x + r <= b) cout<<x - r - a + b - (x + r)<<'\n';
        }
    }


    return 0;
}