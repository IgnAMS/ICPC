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
    vi P;
    ll x = 1;
    while(x < 1000000000) {
        P.push_back(x);
        x *= 3;
    }
    while(t--) {
        int n; cin>>n;
        if(n <= P.size()) {
            cout<<"YES\n";
            rep(i, n) cout<<P[i]<<' '; cout<<'\n';
        }
        else {
            cout<<"NO\n";
        }
    }



    return 0;
}