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
    string s[27];
    s[0] = "a";
    repx(i, 1, 17) s[i] = s[i - 1] + char('a' + i) + s[i - 1];
    string s16 = "";
    rep(i, 100000) s16 += s[16][i];
    
    // cout<<s16.length()<<'\n';
    // cout<<s[15].length()<<'\n';
    // hasta el 15 tiene tamano menor a 10^5
    // s[15].length() = 65535
    // s[16].length() > 10^5
        
    if(n <= 16) cout<<s[n - 1]<<'\n';
    else cout<<s16<<'\n';



    return 0;
}