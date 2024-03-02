    #pragma GCC optimize("Ofast")
    #pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

    // U, R, D, L
    ll dr[] = {-1, 0, 1, 0};
    ll dc[] = {0, 1, 0, -1};

    ll diagdr[] = {-1, 1, 1, -1};
    ll diagdc[] = {-1, -1, 1, 1};

    ll V[60][60];
    char mat[60][60];
    int n, m;

    bool inmat(int i, int j){
        if(0 <= i and i < n and 0 <= j and j < m) return 1;
        return 0;
    }
    vector<ll> C;

    ll dfs(int i, int j, int &left, int &right, int &up, int &down, int &diag, int comp) {
        // cout<<"Estoy en "<<i<<' '<<j<<'\n';
        V[i][j] = comp;
        C[comp]++;
        rep(h, 4) {
            int di = i + dr[h], dj = j + dc[h];
            if(V[di][dj] == -1 and mat[di][dj] != '.' and inmat(di, dj)) {
                if(h == 0) left = 1;
                if(h == 1) up = 1;
                if(h == 2) down = 1;
                if(h == 3) right = 1;
                dfs(di, dj, left, right, up, down, diag, comp);
            }
        }

        rep(h, 4) {
            int di = i + diagdr[h], dj = j + diagdc[h];
            if(V[di][dj] == -1 and mat[di][dj] != '.' and inmat(di, dj)) {
                // cout<<"visitare en diagonal de "<<i<<' '<<j<<" a "<<di<<' '<<dj<<'\n'; 
                diag = 1;
                dfs(di, dj, left, right, up, down, diag, comp);
            }
        }
        
        // cout<<i<<' '<<j<<' '<<left<<' '<<right<<' '<<up<<' '<<down<<' '<<diag<<'\n';
        if(left + right + up + down == 2 and diag == 0) return 1;
        return 0;
    }



    int main(){
        ios::sync_with_stdio(0); cin.tie(0);
        int t; cin>>t;
        while(t--) {
            C.clear();
            cin>>n>>m;
            rep(i, n) rep(j, m) {
                cin>>mat[i][j];
                V[i][j] = -1;
            }
            ll marcados[n][m];
            rep(i, n) rep(j, m) {
                int left, right, up, down, diag;
                if(V[i][j] == -1 and mat[i][j] == '*') {
                    C.push_back(0);
                    dfs(i, j, left, right, up, down, diag, C.size() - 1);
                }
            }

            bool oc = 1;
            ll tamano_final = 0;
            rep(i, n) rep(j, m) {
                ll ady2 = 0;
                ll L1 = 0, L2 = 0, L3 = 0, L4 = 0;
                if(inmat(i + 1, j) and mat[i + 1][j] == '*' and inmat(i, j + 1) and mat[i][j + 1] == '*'){
                    L1 = 1;
                }
                if(inmat(i + 1, j) and mat[i + 1][j] == '*' and inmat(i, j - 1) and mat[i][j - 1] == '*'){
                    L2 = 1;
                }
                if(inmat(i - 1, j) and mat[i - 1][j] == '*' and inmat(i, j + 1) and mat[i][j + 1] == '*'){
                    L3 = 1;
                }
                if(inmat(i - 1, j) and mat[i - 1][j] == '*' and inmat(i, j - 1) and mat[i][j - 1] == '*'){
                    L4 = 1;
                }
                rep(h, 4) {
                    ll di = i + diagdr[h], dj = j + diagdc[h];
                    if(inmat(di, dj) and mat[di][dj] == '*') ady2++;
                }
                if(L1 + L2 + L3 + L4 == 1 and ady2 == 0) {
                    ll tamano = 1;
                    repx(h, i + 1, n) {
                        if(mat[h][j] == '.') break;
                        tamano++;
                    }
                    repx(h, j + 1, m) {
                        if(mat[i][h] == '.') break;
                        tamano++;
                    }
                    for(int h = i - 1; h >= 0; h--) {
                        if(mat[h][j] == '.') break;
                        tamano++;
                    }
                    for(int h = j - 1; h >= 0; h--) {
                        if(mat[i][h] == '.') break;
                        tamano++;
                    }
                    // cout<<"centro en "<<i<<' '<<j<<" de tamano "<<tamano<<'\n';
                    if(tamano != C[V[i][j]]) oc = 0;
                    if(tamano != 3) oc = 0;
                    tamano_final += tamano;
                }
            }
            ll suma = 0;
            for(auto u: C) suma += u;
            // cout<<oc<<' '<<tamano_final<<' '<<suma<<'\n';
            if(oc == 0 or tamano_final != suma) cout<<"NO\n";
            else cout<<"YES\n";
        }


        return 0;
    }