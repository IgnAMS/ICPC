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
    int n = 6;
    vl A(n); rep(i, n) cin>>A[i];
    sort(A.begin(), A.end());
    map<ll, ll> mp;
    ll mx = A[1] - A[0];
    rep(i, n - 1) {
        if(!mp.count(A[i + 1] - A[i])) mp[A[i + 1] - A[i]] = 0;
        mp[A[i + 1] - A[i]]++;
        if(mp[A[i + 1] - A[i]] > mp[mx]) mx = A[i + 1] - A[i];
    }
    // solo hay una diferencia
    if(mp.size() == 1) {
        if(A[0] - mx > 0 and mx != 0) cout<<A[0] - mx<<'\n';
        cout<<A[n - 1] + mx<<'\n';
    }
    else {
        rep(i, n - 1) if(A[i + 1] - A[i] != mx) {
            cout<<A[i] + mx<<'\n';
        }
    }




    return 0;
}