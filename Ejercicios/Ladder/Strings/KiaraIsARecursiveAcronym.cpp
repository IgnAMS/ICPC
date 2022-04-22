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
    int n; cin>>n;
    vector<string> lineas(n);
    set<char> S;
    rep(i, n) {
        cin>>lineas[i];
        S.insert(lineas[i][0]);
    }
    bool can = 0;
    rep(i, n) {
        bool yes = 1;
        for(auto c: lineas[i]) if(!S.count(c)) yes = 0;
        can |= yes;
    }
    cout<<(can? 'Y': 'N')<<'\n';





    return 0;
}