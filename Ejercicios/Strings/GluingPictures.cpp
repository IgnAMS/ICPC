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
#define pb push_back
#define mp make_pair
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

struct SA
{
    int sz, l; vi L, Lk, S, C, T;
    vector<vi> N, Ilk;

    SA(string s, int n) : L(2 * n), Lk(2 * n), C(2 * n), N(2 * n, vi(26, -1))
    {
        l = L[0] = 0, Lk[0] = -1, sz = 1; int p;
        for (char c : s) p = extend(c - 'A');
        Ilk.resize(sz); S.assign(sz, -1);
        rep(i, sz) if (i) Ilk[Lk[i]].pb(i);
        T.assign(sz, 0); while (p != -1) T[p] = 1, p = Lk[p];
    }
    int extend(char c){
        int cur = sz++, p = l; C[cur] = 0, L[cur] = L[l] + 1;
        while (p != -1 && N[p][c] == -1) N[p][c] = cur, p = Lk[p];
        if (p == -1) { Lk[cur] = 0, l = cur; return cur; }
        int q = N[p][c];
        if (L[p] + 1 == L[q]) { Lk[cur] = q, l = cur; return cur; }
        int w = sz++; C[w] = 1, L[w] = L[p] + 1, Lk[w] = Lk[q], N[w] = N[q];
        while (p != -1 && N[p][c] == q) N[p][c] = w, p = Lk[p];
        Lk[q] = Lk[cur] = w, l = cur; return cur;
    }
    int size(int p)
    {
        if (S[p] != -1) return S[p];
        for (int i : Ilk[p]) S[p] += size(i);
        return S[p] += (1 - C[p]) + 1;
    }
};



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    SA sa(s, s.length());
    int q; cin>>q;
    rep(_, q){
        string line; cin>>line;
        int j = 0;
        int p = 0, u;
        int ans = 0;
        while(j < line.size()){
            p = 0;
            u = line[j] - 'A';
            ans++;
            if(sa.N[p][u] == -1) { ans = -1; break; }
            while(j < line.size() and sa.N[p][u] != -1){
                p = sa.N[p][u];
                j++;
                if(j == line.size()) break;
                u = line[j] - 'A';
            }
        }
        cout<<ans<<'\n';
    }
    



    return 0;
}