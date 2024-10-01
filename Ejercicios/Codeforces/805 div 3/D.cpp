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
    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        int n = s.length();
        ll suma = 0;
        rep(i, n) suma += s[i] - 'a' + 1;
        ll p; cin>>p;
        vector<ii> P(n);
        rep(i, n) P[i] = {s[i] - 'a' + 1, i};
        sort(P.begin(), P.end(), greater<ii>()); 
        vi B(n, 1);
        int j = 0;
        while(j < n and suma > p) {
            // cerr<<j<<' '<<suma<<' '<<p<<'\n';    
            suma -= P[j].ff; 
            B[P[j].ss] = 0;
            j++;
        }
        rep(i, n) if(B[i]) cout<<s[i]; cout<<'\n';

    }





    return 0;
}