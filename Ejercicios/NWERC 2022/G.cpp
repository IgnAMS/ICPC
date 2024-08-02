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
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll largo = 30;
    cout<<"1"<<endl;
    cout<<endl;

    // right
    repx(i, 1, largo) cout<<1<<endl;
    cout<<endl;

    // flip 
    cout<<"0"<<endl;
    cout<<endl;
    
    // left
    repx(i, 1, largo) cout<<1<<endl;
    cout<<endl;

    largo = 30;
    ll A[largo] = {
        0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 
        1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1
    };
    
    if(A[0] != 1) cout<<0<<endl;

    repx(i, 1, largo) {
        // cout<<"? right"<<endl;
        // cin>>R[i];
        cout<<1<<endl;
        if(1 != A[i]) {
            // cout<<"? flip"<<endl;
            // ll x; cin>>x;
            cout<<0<<endl;
        }
    }
    cout<<endl;

    rep(_, 14) cout<<1<<endl;
    cout<<endl;
    
    rep(i, largo) cout<<A[i]<<endl;

    return 0;
}