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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

template <class T>
class FT2D
{
    vector<vector<T>> t;
    int n, m;

public:
    FT2D() {}
    FT2D(int n, int m) : n(n), m(m) { t.assign(n, vector<T>(m, 0)); }

    void add(int r, int c, T value)
    {
        for (int i = r; i < n; i |= i + 1)
            for (int j = c; j < m; j |= j + 1)
                t[i][j] += value;
    }

    T sum(int r, int c)
    {
        T res = 0;
        for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = c; j >= 0; j = (j & (j + 1)) - 1)
                res += t[i][j];
        return res;
    }

    T sum(int r1, int c1, int r2, int c2)
    {
        return sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) +
               sum(r1 - 1, c1 - 1);
    }

    T get(int r, int c) { return sum(r, c, r, c); }

    void set(int r, int c, T value) { add(r, c, -get(r, c) + value); }
};



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        FT2D<ll> F(n, n);
        string com; 
        while(cin>>com and com != "END") {
            if(com == "SET") {
                ll x, y, num; cin>>x>>y>>num;
                F.set(x, y, num);
            }
            else {
                ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
                cout<<F.sum(x1, y1, x2, y2)<<'\n';
            }
        }

    }

    return 0;
}