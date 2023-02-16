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
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


ll bp(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % 1000;
        a = (a * a) % 1000;
        b /= 2;
    }
    return res;
} 


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n, k; cin>>n>>k;
        ll n2 = n % 1000;
        n2 = bp(n2, k);

        db logn = log10(n);
        logn -= (int)logn;
        logn *= k;
        logn -= (int)logn;
        ll n3 = (int)(pow(10, logn) * 100.0);


        cout<<n3<<"...";
        ll pot10 = 1, pot = 3;
        while(n2 / pot10 > 0) pot--, pot10 *= 10;
        while(pot--) cout<<"0";
        if(n2 != 0) cout<<n2<<'\n';
        else cout<<'\n';
    
    }





    return 0;
}