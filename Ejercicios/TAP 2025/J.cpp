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
    vl A[n], B[n];
    map<ll, ll> contA, contB;
    rep(i, n) {
        int k; cin>>k;
        A[i].resize(k);
        rep(j, k) {
            cin>>A[i][j];
            if(!contA.count(A[i][j])) contA[A[i][j]] = 0;
            contA[A[i][j]]++;
        }
    }

    rep(i, n) {
        int k; cin>>k;
        B[i].resize(k);
        rep(j, k) {
            cin>>B[i][j];
            if(!contB.count(B[i][j])) contB[B[i][j]] = 0;
            contB[B[i][j]]++;
        }
    } 

    bool pos = 1;
    for(auto [k, v]: contA) if(!contB.count(k) or contB[k] != v) pos = 0;
    if(contA.size() != contB.size()) pos = 0;
    if(!pos) {
        cout<<"N\n";
        return 0;
    }
    if(n == 1) {
        rep(i, A[0].size()) if(A[0][i] != B[0][i]) {
            cout<<"N\n";
            break;
        }
        cout<<"S\n";
        return 0;
    }
    if(n >= 3) {
        cout<<"S\n";
        return 0;
    }

    // n == 2
    // solo puedo mover un bloque del mismo tipo del lado grande al lado pequeño
    // es suficiente con verificar ver los bloques diferentes al minimo que se pongan en su posicion
    ll mn = 0;
    if(A[0].size()) mn = A[0].back();
    if(A[1].size()) mn = min(mn, A[1].back());
    pos = 1;
    rep(i, 2) {
        rep(j, A[i].size()) {
            if(A[i][j] == mn) break;
            if(j >= B[i].size()) {
                pos = 0;
                break;
            }
            if(A[i][j] != B[i][j]) {
                pos = 0;
                break;
            }
        } 
    }
    cout<<(pos? "S": "N")<<'\n';
    
    return 0;
}