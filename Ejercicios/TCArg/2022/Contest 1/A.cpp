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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    map<string, int> mp;
    
    vector<string> A(n);
    rep(i, n) {
        cin>>A[i];
        if(!mp.count(A[i])) mp[A[i]] = 0;
        mp[A[i]]++;
        if(mp[A[i]] >= 2) cout<<"YES\n";
        else cout<<"NO\n";
    }




    return 0;
}