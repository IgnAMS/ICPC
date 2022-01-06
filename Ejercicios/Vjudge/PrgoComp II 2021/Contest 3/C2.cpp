#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii, int> iii;
typedef double db;
#define ff first
#define ss second


struct Element{
    int num, col, comp;
    Element() {}
    Element(int num, int col, int comp): num(num), col(col), comp(comp) {}
    bool operator<(const Element& e) const { 
        return iii(ii(e.num, e.col), e.comp) < iii(ii(num, col), comp);
    }
    bool operator==(const Element & e) const { return e.num == num and e.col == col and e.comp == comp; }
    bool operator!=(const Element & e) const { return !(e.num == num and e.col == col and e.comp == comp); }
};

ll N;

struct Node{
    int v, l, r;
    vector<Element> vL, vR;
    Node(){
        v = 0;
        vL.resize(N, Element(-1, -1, -1)), vR.resize(N, Element(-1, -1, -1));
    }
    Node(vector<int>& vec, int c){
        r = c, l = c;
        v = N; vL.resize(N);
        int i = 0; 
        while(i < N){
            vL[i] = Element(vec[i], c, i);
            int j = i+1;
            while(j < N and vec[i] == vec[j]) vL[j++] = vL[i], v--;
            i = j;
        }
        vR = vL;
    }
    Node(const Node &a, const Node &b): vL(a.vL), vR(b.vR), l(a.l), r(a.r){ // a el de la izquierda y b el de la derecha
        v = a.v + b.v;
        map<Element, Element> mapa;
        vector<int> changeL(N, -1);
        vector<int> changeR(N, -1);
        int cont = 0;
        rep(i, N){
            rep(j, i) {
                if(b.vL[i] == b.vL[j]) changeL[i] = changeL[j];
                if(a.vR[i] == a.vR[j]) changeR[i] = changeR[j];
            }
            if(a.vR[i].num == b.vL[i].num and a.vR[i].num != -1){
                if(changeL[i] == -1 and (changeR[i] == -1 or (changeR[i] != -1 and a.vR[changeR[i]] != a.vR[i]))){ // b -> changeR[a]
                    cont++;
                    if(changeR[i] != -1) changeL[i] = changeR[i]; // el de mi derecha tiene una referencia
                    else changeL[i] = i; // 0 es cambiar a la fila de la izquierda
                }
                else if(changeR[i] == -1 and a.vR[changeL[i]] != a.vR[i]){ // b ya tiene uno apuntando a a, por ende a -> b -> a
                    cont++;
                    changeR[i] = changeL[i];
                }
            }
        }
        v -= cont;
        
        // cout<<cont<<'\n';
        // cout<<v<<'\n';
        // cout<<"left: "; rep(i, N) cout<<vL[i].num<<' '; cout<<'\n';
        // cout<<"midleft: "; rep(i, N) cout<<a.vR[i].num<<' '; cout<<'\n';
        // cout<<"midright: "; rep(i, N) cout<<b.vL[i].num<<' '; cout<<'\n';
        // cout<<"right: "; rep(i, N) cout<<vR[i].num<<' '; cout<<"\n\n";
        rep(i, N) rep(j, N) if(changeR[i] != -1 and a.vR[i] == vL[j]) vL[j] = a.vR[changeR[i]];
        rep(i, N) rep(j, N) if(changeL[i] != -1 and b.vL[i] == vR[j]) vR[j] = a.vR[changeL[i]];
    }
};

// 0 - indexed / inclusive - exclusive
template <class node>
struct ST
{
    vector<node> t; int n;

    ST(vector<node> &arr, int n) : n(n), t(n * 2)
    {
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i) {
            // cout<<"formo el nodo "<<i<<'\n';
            t[i] = node(t[i << 1], t[i << 1 | 1]);
        }
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
    int m, q; cin>>N>>m>>q;
    vector<vector<int>> V(m, vector<int>(N));
    rep(i, N) rep(j, m) cin>>V[j][i];
    vector<Node> A;
    rep(j, m) A.push_back(Node(V[j], j));

    ST<Node> stl(A, m);

    while(q--){
        int l, r; cin>>l>>r; l--, r--;
        // cerr<<"query "<<l<<' '<<r<<'\n'; 
        cout<<stl.query(l, r+1).v<<'\n';
    }


    return 0;
}