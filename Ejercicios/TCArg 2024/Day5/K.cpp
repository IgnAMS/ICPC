#pragma GCC optimize("Ofast")
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
// g++ -std=c++11 K.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 .cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        cout<<"1 "<<n - 1<<" "<<1;
        repx(i, 2, n + 1) cout<<" "<<i; cout<<endl;
        ll diam; cin>>diam;

        ll l = 2, r = n;

        while(l < r) {
            ll m = (l + r) / 2;
            // cout<<"l: "<<l<<", r: "<<r<<", m: "<<m<<endl; 
            
            cout<<"1 "<<m - l + 1<<" "<<1;
            repx(i, l, m + 1) cout<<" "<<i; cout<<endl;
            ll x; cin>>x;
            if(x == diam) r = m;
            else l = m + 1;
        }
        // cout<<"l: "<<l<<", r: "<<r<<endl; 
        // l es el punto mas lejano de 1
        cout<<"1 "<<n - 1<<" "<<l;
        repx(i, 1, n + 1) if(i != l) cout<<" "<<i; cout<<endl;
        ll real_diam; cin>>real_diam;
        cout<<"-1 "<<real_diam<<endl;

    }

    return 0;
}