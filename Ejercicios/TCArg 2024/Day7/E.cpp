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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string s; cin>>s;
        char c = s[0];
        ll ind = n;
        repx(i, 1, n) {
            if(i == 1 and s[i] == s[i - 1]) {
                ind = 1;
                break;
            }
            if(s[i] > s[i - 1]) {
                ind = i;
                break;
            }
        }
        
        rep(i, ind) cout<<s[i]; 
        rep(i, ind) cout<<s[ind - i - 1];
        cout<<'\n';
    }





    return 0;
}