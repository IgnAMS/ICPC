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
        ll a, b, x; cin>>a>>b>>x;
        bool oc = 0;
        ll cont = 0;
        while((a > x or b > x) and (a != 0 and b != 0)) {
            // if(cont++ > 30) break;
            if(a < b) swap(a, b); // a siempre es el mayor
            if((a - x) % b == 0) oc = 1;
            a = a - max(1LL, (a - x) / b) * b;
        }
        if(a == x or b == x) oc = 1;
        if(oc) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}