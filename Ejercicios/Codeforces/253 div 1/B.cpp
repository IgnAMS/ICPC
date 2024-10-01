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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    bool uno = 0;
    db P[n];
    rep(i, n) {
        cin>>P[i];
        if(P[i] == 1) uno = 1;
    }
    if(uno) {
        cout<<"1\n";
        return 0;
    }

    sort(P, P + n);
    reverse(P, P + n);
    db sum = 0, prod = 1;
    rep(i, n) if(sum < 1) {
        sum += P[i] / (1 - P[i]);
        prod *= (1 - P[i]);
    }
    cout<<setprecision(10)<<fixed<<sum * prod<<'\n';
    return 0;
}