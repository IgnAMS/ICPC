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

struct Node
{
    int v;
    Node() { v = 0; } // neutro
    Node(int v) : v(v) {}
    Node(const Node &a, const Node &b) { v = a.v + b.v; }
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
    int t; cin>>t;
    while(t--) {
        ll n, k; cin>>n>>k;
        vl A(n); rep(i, n) cin>>A[i];
        rep(i, n) A[i]--;
        vl Mn(k, n), Mx(k, 0);
        set<ll> S; 
        rep(i, n) S.insert(A[i]);
        rep(i, n) {
            vl Erase;
            auto it = S.upper_bound(A[i]);
            if(it == S.begin()) continue;
            for(auto it2 = it; it2 != S.begin(); it2--) {
                Mn[*prev(it2)] = i;
                Erase.pb(*prev(it2));
            }
            for(auto u: Erase) S.erase(u);
        }

        rep(i, n) S.insert(A[i]);
        rep(i, n) {
            vl Erase;
            auto it = S.upper_bound(A[n - i - 1]);
            if(it == S.begin()) continue;
            for(auto it2 = it; it2 != S.begin(); it2--) {
                Mx[*prev(it2)] = n - i - 1;
                Erase.pb(*prev(it2));
            }
            for(auto u: Erase) S.erase(u);
        }
        
        // rep(i, k) cout<<Mn[i]<<' '<<Mx[i]<<'\n'; cout<<'\n';
        rep(i, n) S.insert(A[i]);
        rep(i, k) {
            if(S.count(i)) {
                cout<<2 * (Mx[i] - Mn[i] + 1)<<' ';
            }
            else cout<<"0 "; 
        } 
        cout<<'\n';

    }


    return 0;
}