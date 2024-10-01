#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;

struct Node
{
    ll v;
    Node() { v = 0; } // neutro
    Node(int v) : v(v) {}
    Node(const Node &a, const Node &b) { v = __gcd(a.v, b.v); }
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
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll h;
        vector<Node> A(n); rep(i, n) { cin>>h; A[i].v = h; } 
        vector<Node> Dif(n-1); rep(i, n-1) Dif[i].v = abs(A[i].v - A[i+1].v);
        ST<Node> st(Dif, n-1);
        int j = 0, ans = 1;
        // cerr<<st.query(3, 3).v<<'\n';
        // rep(i, n-1) cout<<Dif[i].v<<' '; cout<<'\n';
        rep(i, n-1){
            while(j <= i and st.query(j, i + 1).v == 1) j++;
            cerr<<i<<' '<<j<<'\n';
            ans = max(ans, i-j+2);
        }
        cout<<ans<<'\n';


    }



    return 0;
}