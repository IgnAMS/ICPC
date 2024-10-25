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
    ll n; cin>>n;
    if(n % 2 == 1) {
        cout<<0<<'\n';
        return 0;
    }

    // n = 4 -> 1 + 4 = 5
    // n = 6 -> 

    for(int i = 4; i <= 10000; i += 2) {
        cout<<i<<' '<<double(180) * (i - 2) / i<<'\n';
    }


    return 0;
}