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
    // cout<<(1LL<<60)<<'\n';
    ll l, r; cin>>l>>r;
    ll acc = 0;
    ll ans = 0;
    for(ll i = 60; i >= 0; i--) {
        if(r & (1LL<<i)) acc += (1LL<<i);
        if(acc != 0 and acc - 1 >= l) { 
            ans = acc ^ (acc - 1); 
            break;
        }
    }
    cout<<ans<<'\n';


    return 0;
}