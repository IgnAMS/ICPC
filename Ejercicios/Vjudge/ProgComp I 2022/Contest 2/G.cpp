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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int n = s.length();
    vector<ll> S;
    vector<ii> P;
    vector<ll> M(n, -1);
    ll cont = 0;
    rep(i, n) {
        if(s[i] == '(') S.push_back(i);
        else if(s[i] == ')') {
            // cerr<<"entre aca\n"; cerr<<S.back()<<'\n';
            // cont++;
            M[S.back()] = cont; 
            M[i] = cont;
            S.pop_back();
            cont++;
        }
    }
    // cerr<<"entre aca?\n";
    // rep(j, n) cout<<M[j]<<' '; cout<<'\n';
    for(int i = (1 << cont) - 2; i >= 0; i--) {
        // cout<<i<<'\n';
        rep(j, n) if(M[j] == -1 or ((1 << M[j]) & i)) cout<<s[j];
        cout<<'\n'; 
    }





    return 0;
}