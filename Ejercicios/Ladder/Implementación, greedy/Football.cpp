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
    ll n, g; 
    while(cin>>n>>g) {
        vi S(n), R(n), D(n);
        rep(i, n) cin>>S[i]>>R[i];
        rep(i, n) D[i] = R[i] - S[i];
        sort(D.begin(), D.end());
        ll puntos = 0;
        rep(i, n) {
            if(D[i] < 0) puntos += 3;
            else {
                if(g >= D[i] + 1) puntos += 3, g -= D[i] + 1;
                else if(g >= D[i]) puntos += 1, g -= D[i];
            }
        }
        cout<<puntos<<'\n';
    }


    return 0;
}