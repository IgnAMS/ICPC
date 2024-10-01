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
    int t; cin>>t;
    while(t--) {
        ll n, k, x; cin>>n>>k>>x;
        if(x != 1) {
            cout<<"YES\n";
            cout<<n<<'\n';
            rep(i, n) cout<<1<<' '; cout<<'\n'; 
        }
        else { // x == 1
            if(k == 1 or (k == 2 and n % 2 != 0)) {
                cout<<"NO\n";
            }
            else { // n % 2 != 0
                cout<<"YES\n";
                if(k == 2 or (n % 2 == 0)) {
                    cout<<n / 2<<'\n';
                    rep(i, n / 2) cout<<2<<' '; cout<<'\n';
                }
                // k = 3
                else {
                    cout<<1 + (n - 3) / 2<<'\n';
                    cout<<"3 ";
                    rep(i, (n - 3) / 2) cout<<2<<' '; cout<<'\n';
                }
            }
        }
    }




    return 0;
}