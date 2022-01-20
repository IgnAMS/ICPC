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

vi prev_day(int d, int m, int y) {
    if(d == 1) {
        if(m == 3 and y % 4 == 0 and y % 100 != 0) return {29, 2, y};
        if(m == 3 and !(y % 4 == 0 and y % 100 != 0)) return {28, 2, y};
        if(m == 1) return {31, 12, y-1};
        if(m == 2 or m == 4 or m == 6 or m == 8 or m == 9 or m == 11) return {31, m - 1, y};
        return {30, m - 1, y};
        // enero: 1, marzo: 3, mayo: 5, julio: 7, agosto: 8, octubre: 10, diciembre: 12
    }
    return {d-1, m, y};
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; 
    while(cin>>n and n) {
        map<vi, ll> mapa;
        rep(i, n) {
            ll d, m, y, c; cin>>d>>m>>y>>c;
            mapa[{d, m, y}] = c;
        }
        ll cont = 0, ans = 0;
        for(auto u: mapa){
            vi prev = prev_day(u.ff[0], u.ff[1], u.ff[2]);
            if(mapa.count(prev)) {
                cont++; 
                ans += u.ss - mapa[prev];
            }
        }
        cout<<cont<<' '<<ans<<'\n';
    }



    return 0;
}