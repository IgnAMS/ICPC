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
    string ans; cin>>ans;
    int n; cin>>n;
    bool inicio = 0, fin = 0;
    rep(i, n) {
        string aux; cin>>aux;
        if(aux == ans) inicio = fin = 1;
        if(aux[0] == ans[1]) inicio = 1;
        if(aux[1] == ans[0]) fin = 1;
    }
    cout<<((inicio and fin)? "YES": "NO")<<'\n';



    return 0;
}