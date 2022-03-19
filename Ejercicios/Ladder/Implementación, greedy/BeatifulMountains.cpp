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
// g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

struct Mx {
    ll i, x;
    Mx() { i = -1, x = -1; }
    Mx(ll i, ll x): i(i), x(x) {}
    Mx(const Mx& a, const Mx& b) {
        if(a.x > b.x) i = a.i, x = a.x;
        else if(a.x == b.x) i = min(a.i, b.i), x = b.x;
        else i = b.i, x = b.x;
    }
};  

struct Mn {
    ll i, x;
    Mn() { i = 10000000000, x = 10000000000; }
    Mn(ll i, ll x): i(i), x(x) {}
    Mn(const Mn& a, const Mn& b) {
        if(a.x < b.x) i = a.i, x = a.x;
        else if(a.x == b.x) i = min(a.i, b.i), x = b.x;
        else i = b.i, x = b.x;
    }
};

// 0 - indexed / inclusive - exclusive
template <class node>
struct ST
{
    vector<node> t; int n;

    ST(vector<node> &arr, int N) : n(N), t(N * 2)
    {
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i) t[i] = node(t[i << 1], t[i << 1 | 1]);
    }
    void set(int p, const node &value)
    {
        for (t[p += n] = value; p >>= 1;)
            t[p] = node(t[p << 1], t[p << 1 | 1]);
    }
    node query(int l, int r)
    {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) ansl = node(ansl, t[l++]);
            if (r & 1) ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vi A(n); rep(i, n) cin>>A[i];

    // query de mayor interseccion hacia mi izquierda
    vector<ii> S; S.push_back(ii(1e10, - 1));
    vector<Mx> mxL(n); // primero estrictamente mayor a mi izquierda
    rep(i, n) {
        if(A[i] != -1) {
            while(S.back().ff <= A[i]) S.pop_back();
            mxL[i].x = S.back().ss;
            S.push_back(ii(A[i], i));
        }
        else mxL[i].x = -1;
    }
    
    // query de minimo a mi derecha
    S.clear(); S.push_back(ii(1e10, n));vector<Mn> mxR(n); // primero estrictamente mayor a mi derecha
    for(int i = n - 1; i >= 0; i--) {
        if(A[i] != -1){
            while(S.back().ff <= A[i]) S.pop_back();
            mxR[i].x = S.back().ss;
            S.push_back(ii(A[i], i));
        }
        else mxR[i].x = n;
    }
    rep(i, n) mxL[i].i = i, mxR[i].i = i;

    vector<Mx> Aux(n);
    rep(i, n) Aux[i].x = A[i], Aux[i].i = i;
    ST<Mx> QL(mxL, n); // queries del lado izquierdo
    ST<Mn> QR(mxR, n); // queries del lado derecho
    ST<Mx> Q(Aux, n); // query del maximo
    
    bool pos = 0;
    repx(i, 3, n + 1) { // queries
        bool aux = 1;
        rep(j, (n + i - 1) / i) {
            ll l = i * j, r = min(n - 1, i * (j + 1) - 1);
            ll maxind = Q.query(l, r + 1).i;
            if(n - l < 3) { aux = 0; continue; }
            // todos son -1
            if(A[maxind] == -1) continue;
            if(maxind == l and (A[maxind] == A[maxind + 1] or A[maxind + 1] == -1)) {
                maxind++;
            }
            if(maxind == r and (A[maxind - 1] == -1)) maxind--;
            if(maxind == l or maxind == r) { aux = 0; continue; }
            ll qL = QL.query(l, maxind).x, qR = QR.query(maxind + 1, r + 1).x;
            if(qL >= l or qR <= r) aux = 0;
        }
        pos |= aux;
    }

    cout<<(pos? 'Y': 'N')<<'\n';


    return 0;
}