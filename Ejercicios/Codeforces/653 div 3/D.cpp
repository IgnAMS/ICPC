#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt


ll solve(string& s, int l, int r, char c) {
    if(r - l == 1) return s[l] != c;
    ll cont1 = 0, cont2 = 0;
    repx(i, l, (l + r) / 2) if(s[i] != c) cont1++;
    repx(i, (l + r) / 2, r) if(s[i] != c) cont2++;
    return min(cont2 + solve(s, l, (l + r) / 2, c + 1), cont1 + solve(s, (l + r) / 2, r, c + 1));
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    // cout<<(1<<17)<<'\n';
    while(t--) {
        int n; cin>>n;
        string s; cin>>s;
        cout<<solve(s, 0, n, 'a')<<'\n';
    }


    return 0;
}