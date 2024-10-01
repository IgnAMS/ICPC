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
        int n, k; cin>>n>>k;
        ll ans = 0;
        rep(i, n / k) {
            cout<<"? "<<i * k + 1<<endl;
            ll aux; cin>>aux;
            ans ^= aux;
        } 
        if(n % k) {
            // |A| + |C| = k -> |A| = k - (n % k) / 2 
            // B, A, C, D -> B, C, A, D 
            // n - k - (n%k) / 2 + 1 = 12 - 8 - 2 = 12 - 10 = 2
            // n - k + 1 = 12 - 8 + 1 = 5
            cout<<"? "<<n - k - (n % k) / 2 + 1<<endl;
            ll aux; cin>>aux;
            ans ^= aux;
            cout<<"? "<<n - k + 1<<endl;
            cin>>aux;
            ans ^= aux;
        }
        cout<<"! "<<ans<<endl;
    }

    return 0;
}