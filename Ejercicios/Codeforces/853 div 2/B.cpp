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
        string A; cin>>A;
        ll cambios = 0;
        bool segment = 0;
        rep(i, n / 2) {
            if(A[i] == A[n - i - 1]) cambios += segment, segment = 0;
            if(A[i] != A[n - i - 1]) segment = 1;
        }
        if(segment) cambios++;
        if(cambios >= 2) cout<<"No\n";
        else cout<<"Yes\n";
    }





    return 0;
}