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
    int v;
    vector<Element> vL, vR;
    Node(){
        v = 0;
        vL.resize(N, Element(-1, -1, -1)), vR.resize(N, Element(-1, -1, -1));
    }
    Node(vector<int>& vec, int c){
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
    Node(const Node &a, const Node &b): vL(a.vL), vR(b.vR){ // a el de la izquierda y b el de la derecha
        v = a.v + b.v;
        map<Element, Element> mapa;
        rep(i, N){
            if(a.vR[i].num == b.vL[i].num and a.vR[i].num != -1){
                if(mapa.count(b.vL[i]) and mapa[b.vL[i]] != a.vR[i]) mapa[a.vR[i]] = mapa[b.vL[i]];
                else if(!mapa.count(b.vL[i])) mapa[b.vL[i]] = a.vR[i];
            }
        }
        // cout<<v<<'\n';
        // for(auto u: mapa) { 
        //     cout<<u.ff.num<<' '<<u.ff.col<<' '<<u.ff.comp<<'\n';
        //     cout<<u.ss.num<<' '<<u.ss.col<<' '<<u.ss.comp<<"\n\n";
        // }
        v -= ll(mapa.size());
        
        // cout<<v<<'\n';
        // cout<<"left: "; rep(i, N) cout<<vL[i].num<<' '; cout<<'\n';
        // cout<<"midleft: "; rep(i, N) cout<<a.vR[i].num<<' '; cout<<'\n';
        // cout<<"midright: "; rep(i, N) cout<<b.vL[i].num<<' '; cout<<'\n';
        // cout<<"right: "; rep(i, N) cout<<vR[i].num<<' '; cout<<"\n\n";
        
        rep(i, N) if(mapa.count(vL[i])) vL[i] = mapa[vL[i]];
        rep(i, N) if(mapa.count(vR[i])) vR[i] = mapa[vR[i]];
    }
};

// 0 - indexed / inclusive - exclusive
template <class node>
struct STL
{
    vector<node> st; int n;

    void build(int u, int i, int j, vector<node> &arr)
    {
        if (i == j) { st[u] = arr[i]; return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m, arr), build(r, m + 1, j, arr);
        // cout<<"nodo a crear "<<u<<'\n';
        st[u] = node(st[l], st[r]);
    }
    
    node query(int a, int b, int u, int i, int j)
    {
        if (j < a || b < i) return node();
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (a <= i && j <= b) return st[u];
        // cout<<"voy a usar el segmento "<<i<<' '<<j<<'\n';
        return node(query(a, b, l, i, m), query(a, b, r, m + 1, j));
    }

    STL(vector<node> &v, int m) : n(m), st(m * 4 + 5) { build(0, 0, n - 1, v); }
    node query(int a, int b) { return query(a, b, 0, 0, n - 1); }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int m, q; cin>>N>>m>>q;
    vector<vector<int>> V(m, vector<int>(N));
    rep(i, N) rep(j, m) cin>>V[j][i];
    vector<Node> A;
    rep(j, m) A.push_back(Node(V[j], j));

    STL<Node> stl(A, m);

    while(q--){
        int l, r; cin>>l>>r; l--, r--;
        // cerr<<"query "<<l<<' '<<r<<'\n';
        cout<<stl.query(l, r).v<<'\n';
    }


    return 0;
}