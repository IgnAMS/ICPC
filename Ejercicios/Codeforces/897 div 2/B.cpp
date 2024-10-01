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
        int n; cin>>n;
        string s; cin>>s;
        ll dif = 0;
        rep(i, n / 2) dif += (s[i] != s[n - i - 1]);
        string b = ""; rep(i, n + 1) b += '0';
        if(n % 2 == 0) {
            rep(i, n + 1) if(i >= dif and i <= n - dif and (i - dif) % 2 == 0) b[i] = '1';
        }
        else {
            rep(i, n + 1) if(i >= dif and i <= n - dif) b[i] = '1';
        }
        cout<<b<<'\n';
    }


    return 0;
}