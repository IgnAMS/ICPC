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
    string s; cin>>s;
    int n = s.length();
    // 0, [1, ..., n], n + 1
    vi PosL(n + 2, 1), PosR(n + 2, 1), L1(n + 2, 0), R0(n + 2, 0), Acc(n + 2, 0);
    ll suma = 0;
    rep(i, n) {
        if(s[i] == '(') suma++;
        else suma--;
        L1[i + 1] = suma;
        if(suma < 0 ) while(i + 1 < n + 2) PosL[++i] = 0;
    } 
    

    suma = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == ')') suma++;
        else suma--;
        R0[i + 1] = suma;
        if(suma < 0) while(i + 1 >= 0) PosR[i + 1] = 0, i--;
    }
    bool pos = 0;
    if(suma == 0) pos = 1;
    PosL[0] = (s[0] == ')'), PosR[n + 1] = (s[n - 1] == '(');
    rep(i, n) {
        suma = 0;
        repx(j, i, n) { // [i + 1, j + 1]
            if(s[j] == '(') suma++;
            else suma--;
            if(L1[i] - suma < 0) break;
            // cout<<"i, j: "<<i<<' '<<j<<"; Pos: "<<PosL[i]<<' '<<PosR[j + 2]<<'\n';
            // cout<<"L, R: "<<L1[i]<<' '<<R0[j + 2]<<"; suma: "<<suma<<"\n\n"; 
            if(PosL[i] and PosR[j + 2] and L1[i] - suma == R0[j + 2]) {
                pos = 1;
                // cout<<"i, j: "<<i<<' '<<j<<' '<<s[i]<<' '<<s[j]<<'\n';
            }
        }
    }
    cout<<(pos? "possible": "impossible")<<'\n';





    return 0;
}