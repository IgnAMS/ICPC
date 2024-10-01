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
        ll a, b; cin>>a>>b;
        ll ans = b - a;
        repx(i, a, b + 1) {
            ll b2 = 0;
            for(int x = 20; x >= 0; x--) {
                if(b & (1 << x) and i & (1 << x)) b2 += (1 << x);
                else if(b & (1 << x)) b2 += (1 << x);
                else if(i & (1 << x)) { b2 += (1 << x); break; }
            }
            ans = min(ans, i + (i | b2) + (1 - a - b));
        }
        cout<<ans<<'\n';
    }


    return 0;
}