#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

vector<ii> dh = {
    {0, 2}, {-1, 1}, {-1, 0}, {0, -1}, {1, 0}, {1, 1}, 
    {-1, 2}, {-1, -1}, {1, -1}, {1, 2}
};
vector<ii> dv =  {
    {0, 1}, {-1, 0}, {0, -1}, {1, -1}, {2, 0}, {1, 1},
    {-1, 1}, {-1, -1}, {2, -1}, {2, 1}
};

char letra(vector<string> &S, int i, int j, int ty){ // todo, *posicion, type
    int n = S.size(), m = S[0].size();
    if(ty == 0){ // 0 es horizontal
        for(char c = 'a'; c <= 'z'; c++) {
            bool oc = 1;
            rep(k, 6){
                int di = i + dh[k].ff, dj = j + dh[k].ss;
                if(0 <= di and di < n and 0 <= dj and dj < m and S[di][dj] == c) oc = 0;
            }
            if(oc) return c;
        }
    }
    else{ // 1 es vertical
        for(char c = 'a'; c <= 'z'; c++) {
            bool oc = 1;
            rep(k, 6){
                int di = i + dv[k].ff, dj = j + dv[k].ss;
                if(0 <= di and di < n and 0 <= dj and dj < m and S[di][dj] == c) oc = 0;
            }
            if(oc) return c;
        }
    }
    //cout<<"llegue aca :c\n";
    return 'a';

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n, m, k; cin>>n>>m>>k;
        int A[n][m]; memset(A, 0, sizeof A);
        bool oc = 1;
        int h = n*m/2 - k;
        // Cumple minimos y quedan pares
        if(n % 2 and (k < m / 2 or  (k - m/2) % 2 != 0)) oc = 0;
        if(m % 2 and (h < n / 2 or (h - n / 2) % 2 != 0)) oc = 0;
        // Si es par se cumplen pares
        if(!(n % 2) and k % 2 != 0) oc = 0;
        if(!(m % 2) and h % 2 != 0) oc = 0;
        // Cota maxima
        if(m % 2 and k * 2 > m/2 * 2 * n) oc = 0;
        if(n % 2 and h * 2 > n/2 * 2 * m) oc = 0;

        if(oc) cout<<"YES\n";
        else { cout<<"NO\n"; continue; }

        vector<string> S(n, ""); rep(i, n) rep(j, m) S[i] += '-'; 
        // n impar, m par
        if(n % 2){
            // Relleno la primera columna
            rep(j, m / 2) {
                char c = letra(S, 0, 2 * j, 0);
                S[0][2 * j] = c, S[0][2 * j + 1] = c;
            }
        }
        //cerr<<n<<' '<<m<<'\n';
        int aux = n % 2;
        // Relleno de a pares las k-m/2 que me quedan
        rep(i, (k - aux * m/2)/2){ // se que lo que me qeuda es par, puedo dividir en 2
            int fila = (2 * i) % (n - aux) + aux; // voy cada dos filas
            int col = (2 * i) / (n - aux);
            //cerr<<fila<<' '<<col<<'\n';
            char c = letra(S, fila, col * 2, 0);
            S[fila][col * 2] = c, S[fila][col * 2 + 1] = c;
            c = letra(S, fila + 1, col * 2, 0);
            //cerr<<fila + 1<<' '<<col<<'\n';
            S[fila + 1][col * 2] = c, S[fila + 1][col * 2 + 1] = c;
        }
        // rep(i, n) { rep(j, m) cout<<S[i][j]; cout<<'\n'; }
        // Relleno lo que queda con verticales
        rep(i, n) rep(j, m) if(S[i][j] == '-'){
            char c = letra(S, i, j, 1);
            //cerr<<i<<' '<<j<<'\n';
            S[i][j] = c, S[i+1][j] = c; 
        }
        rep(i, n) { rep(j, m) cout<<S[i][j]; cout<<'\n'; }
        cerr<<n<<' '<<m<<'\n';
    }



    return 0;
}