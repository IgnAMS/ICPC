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


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    ll mod = 1000000007;
    while(t--){
        ll n, k; cin>>n>>k;
        ll ans = 0;
        ll aux = 1;
        for(ll i = 0; i < 32 ; i++){
            if(k & (1LL<<i)) {
                ans = (ans + aux) % mod;
            }
            aux = (aux * n) % mod;
        }
        cout<<ans<<'\n';
    }


    return 0;
}