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
        vector<vector<string>> A(3, vector<string>(n));
        map<string, ll> mp;

        rep(i, n) {
            cin>>A[0][i];
            if(!mp.count(A[0][i])) mp[A[0][i]] = 0;
            mp[A[0][i]]++;
        }
        rep(i, n) {
            cin>>A[1][i];
            if(!mp.count(A[1][i])) mp[A[1][i]] = 0;
            mp[A[1][i]]++;
        }
        rep(i, n) {
            cin>>A[2][i];
            if(!mp.count(A[2][i])) mp[A[2][i]] = 0;
            mp[A[2][i]]++;
        }

        ll puntos1 = 0, puntos2 = 0, puntos3 = 0;
        rep(i, n) {
            if(mp[A[0][i]] == 1) puntos1 += 3;
            if(mp[A[0][i]] == 2) puntos1 += 1;
        }
        rep(i, n) {
            if(mp[A[1][i]] == 1) puntos2 += 3;
            if(mp[A[1][i]] == 2) puntos2 += 1;
        }
        rep(i, n) {
            if(mp[A[2][i]] == 1) puntos3 += 3;
            if(mp[A[2][i]] == 2) puntos3 += 1;
        }
        cout<<puntos1<<' '<<puntos2<<' '<<puntos3<<'\n';
    }





    return 0;
}