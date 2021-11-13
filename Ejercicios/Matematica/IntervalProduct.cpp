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

struct Node{
    int v;
    Node() { v = 1; } // neutro
    Node(int v) : v(v > 0? 1: (v<0? -1: 0)) {}
    Node(const Node &a, const Node &b) { 
        // cout<<"mergarea el nodo "<<a.v<<" con "<<b.v<<'\n';
        v = a.v * b.v; 
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
    int n, q;
    while(cin>>n>>q){
        vector<Node> A(n);
        rep(i, n) cin>>A[i].v; 
        rep(i, n){
            if(A[i].v > 0) A[i].v = 1;
            else if(A[i].v < 0) A[i].v = -1;
            else A[i].v = 0;
        }
        ST<Node> st(A, n);
        rep(i, q){
            string c; cin>>c;
            int u, v; cin>>u>>v;
            
            if(c == "C") {
                // cout<<st.query(u-1, u).v<<'\n';
                st.set(u-1, Node(v));
            }
            else {
                ll val = st.query(u-1, v).v;
                cout<<(val>0? '+': (val < 0? '-': '0'));
            }
        }
        cout<<'\n';


    }


    return 0;
}