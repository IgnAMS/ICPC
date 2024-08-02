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

ll L[100001]; 
string s1 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s2 = "What are you doing while sending \"";
string s3 = "\"? Are you busy? Will you send \"";
string s4 = "\"?";

char solve(ll n, ll x) {
    while(n >= 56 and x > ll(s2.length())) {
        n--;
        x -= ll(s2.length());
    }

    if(x >= L[n]) return '.';
    // cerr<<"entre con "<<n<<' '<<x<<'\n';
    if(n == 0) {    
        return s1[x];
    }

    if(x < ll(s2.length())) return s2[x];
    x -= ll(s2.length());

    if(x < L[n - 1]) return solve(n - 1, x);
    x -= L[n - 1]; 

    if(x < ll(s3.length())) return s3[x];
    x -= ll(s3.length());
    
    if(x < L[n - 1]) return solve(n - 1, x);
    x -= L[n - 1];
    
    return s4[x];    
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin>>q;
    // cout<<s1.length()<<' '<<s2.length()<<' '<<s3.length()<<' '<<s4.length()<<'\n';
    L[0] = ll(s1.length());
    repx(i, 1, 56) {
        L[i] = ll(s2.length()) + L[i - 1] + ll(s3.length()) + L[i - 1] + ll(s4.length());
        // cout<<L[i]<<'\n';
    }
    repx(i, 56, 100001) L[i] = 1e18;
    // cout<<L[0]<<' '<<L[1]<<'\n';
    // cout<<L[55]<<'\n';
    while(q--) {
        ll n, x; cin>>n>>x;
        x--;
        cout<<solve(n, x);
    }
    cout<<'\n';

    return 0;
}