#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<int> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int comp = 0, n;
struct Node
{
    int v = 0;
    vi L, R, LC, RC;
    int l, r; 
    Node() { 
        v = 0;
        L.resize(n, -1); R.resize(n, -1); LC.resize(n, -1); RC.resize(n, -1);
    } // neutro
    Node(vi& V, int l) : L(V), R(V), l(l), r(l) {
        int i = 0, j = 0, prev = comp;
        LC.resize(n), RC.resize(n);
        rep(i, n) {
            int j = i;
            while(j < n and V[j] == V[i]) LC[j] = comp, RC[j] = comp, j++;
            i = j - 1;
            comp++;
        }
        v = comp - prev; // componentes creadas
    }

    Node(const Node &a, const Node &b): L(a.L), R(b.R), LC(a.LC), RC(b.RC), l(a.l), r(b.r) { 
        vi aRC = a.RC, bLC = b.LC;
        int cont = 0;
        rep(i, n) {
            if(a.R[i] == b.L[i] and aRC[i] != bLC[i]) {
                cont++;
                int x = bLC[i];
                rep(j, n) {
                    if(bLC[j] == x) bLC[j] = aRC[i];
                    if(aRC[j] == x) aRC[j] = aRC[i];
                    if(LC[j] == x) LC[j] = aRC[i];
                    if(RC[j] == x) RC[j] = aRC[i];
                }
            }
        }
        v = a.v + b.v - cont;
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
    int m, q; cin>>n>>m>>q;
    int mat[n][m];
    rep(i, n) rep(j, m) cin>>mat[i][j];
    
    vector<Node> A;
    rep(i, m){
        vi aux; rep(j, n) aux.push_back(mat[j][i]);
        A.push_back(Node(aux, i)); 
    }

    ST<Node> st(A, m);
    while(q--) {
        int l, r; cin>>l>>r;
        cout<<st.query(l - 1, r).v<<'\n';
    }


    return 0;
}