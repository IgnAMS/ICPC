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
    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        int conta = 0, contb = 0;
        int n = s.length();
        bool pos = 1;
        rep(i, n) { 
            if(s[i] == 'a') {
                conta++;
                if(contb == 1) pos = 0;
                contb = 0;
            }  
            if(s[i] == 'b') {
                contb++;
                if(conta == 1) pos = 0;
                conta = 0;
            }
        }
        if(conta == 1 or contb == 1) pos = 0;
        cout<<(pos? "YES\n": "NO\n");
    }





    return 0;
}