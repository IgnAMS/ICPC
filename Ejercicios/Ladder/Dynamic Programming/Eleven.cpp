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

pair<int, vector<int>> DP[10][52][900];
int nums[10];
int pares[10];
int total = 0;
ll ans = 0;
pair<bool, vector<int>> dp(int x, int k, int suma){ // busca un caso posible
    if(k == 0 and (suma - (total - suma)) % 11 == 0) { // si es 1 puedo calcular la respuesta
        // computo la respuesta y devuelvo

        return make_pair(1, vector<int>(10, 0));
    }
    if(k == 0 and (suma - (total - suma)) % 11 != 0) return {0, vector<int>()};
    if(x < 0) return make_pair(0, vector<int>());
    if(DP[x][k][suma].ff != -1) return DP[x][k][suma];

    rep(i, min(k, nums[x]) + 1){
        pares[x] = i;
        auto u = dp(x - 1, k - i, suma + x * i);
        if(u.ff) {
            u.ss[x] = i;
            DP[x][k][suma] = {1, u.ss}; // exploro todo el grafo
        }
    }
    if(DP[x][k][suma].ff != -1) return DP[x][k][suma]; 
    return DP[x][k][suma] = {0, vector<int>()};
}

ll compute(){
    
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string linea;
    while(cin>>linea){
        // seteo cosas iniciales
        int n = linea.length();
        memset(nums, 0, sizeof nums);
        memset(pares, 0, sizeof pares);
        ans = 0, total = 0;
        for(auto c: linea) nums[c-'0']++, total += c-'0';
        rep(i, 10) rep(j, n/2 + 2) rep(k, total + 1) {
            DP[i][j][k] = {-1, vector<int>(10, 0)};
        }

        // calculo la respuesta
        auto u = dp(9, n/2, 0);
        cout<<ans<<'\n';
        cerr<<"\n";
    }

    return 0;
}