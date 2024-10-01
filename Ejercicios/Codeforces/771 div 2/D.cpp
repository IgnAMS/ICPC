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

int n, m, mat[1000][1000];

bool check() {
    bool cuadrado = 0, dos = 1;
    rep(i, n - 1) rep(j, m - 1) {
        if(mat[i][j] == mat[i + 1][j] and mat[i][j] == mat[i + 1][j] and mat[i][j] == mat[i + 1][j + 1]) cuadrado = 1;
    }
    rep(i, n) {
        bool aux = 0;
        rep(j, m - 1) if(mat[i][j] == mat[i][j + 1]) aux = 1;
        if(!aux) dos = 0;
    }
    rep(j, m) {
        bool aux = 0;
        rep(i, n - 1) if(mat[i][j] == mat[i + 1][j]) aux = 1;
        if(!aux) dos = 0;
    } 
    return dos and cuadrado;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, n) rep(j, m) cin>>mat[i][j];
    if(!check()) { cout<<"-1\n"; return 0; }




    






    return 0;
}