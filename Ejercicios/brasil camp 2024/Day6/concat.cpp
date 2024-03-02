#pragma GCC optimize("Ofast")
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

int n;
const int mxN = 505;
string mat[mxN][mxN];
ll Sz[mxN];
string S[mxN];

vector<int> P;
int match(string &p, string &t) {
    int n = p.size(), m = t.size(), L[n]; L[0] = 0;
    rep(j, n - 1) {
        int i = L[j]; while (p[i] != p[j + 1] && i) i = L[i - 1];
        L[j + 1] = (p[i] == p[j + 1] ? i + 1 : 0);
    }
    int ans = 0, i = 0; 
    rep(j, m) {
        while (p[i] != t[j] and i) i = L[i - 1];
        if (p[i] == t[j] and ++i == n) {
            i = L[n - 1];
            if(j != n - 1 and j != 2 * n - 1) {
                P.pb(j);
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    ll total_length = 0;
    
    rep(i, n) rep(j, n) {
        cin>>mat[i][j];
        if(i != j) total_length += mat[i][j].length();
    }

    if(n == 2) {
        string duplicate = mat[0][1] + mat[0][1];
        ll matches = match(mat[1][0], duplicate); 
        if(matches == 0 or mat[0][1].length() != mat[1][0].length() or mat[0][1].length() == 1) {
            cout<<"NONE\n";
        }
        else if(matches == 1) {
            cout<<"UNIQUE\n";
            ll l1 = P[0] - (int)mat[1][0].length();
            for(int i = 0; i <= l1; i++) cout<<mat[0][1][i];
            cout<<'\n';
            for(int i = l1 + 1; i < (int)mat[1][0].length(); i++) cout<<mat[0][1][i];
            cout<<'\n';
        }
        else if(matches >= 2) {
            cout<<"MANY\n";
        }
        return 0;
    }


    // cada string aparece 2 * (n - 1) veces por lo que debe ser multiplo de 2 * n - 1
    if(total_length % 2 * (n - 1) != 0) {
        cout<<"NONE\n";
        return 0;
    }
    total_length /= 2 * (n - 1);

    bool pos = 1;
    rep(i, n) {
        // total_length + (n - 2) * Sz[i] = sum |t[i, j]| : j != i
        // -> Sz[i] = (sum |t[i, j]| - total_length) / (n - 2)
        ll curr = 0;
        rep(j, n) if(j != i) curr += mat[i][j].length();
        if(curr < total_length or (curr - total_length) % (n - 2) != 0) {
            pos = 0;
        }
        else {
            Sz[i] = (curr - total_length) / (n - 2);
            S[i] = "";
            ll ind = i > 0? 0: 1;
            rep(k, Sz[i]) S[i] += mat[i][ind][k];
            if(Sz[i] == 0) pos = 0;
        }
    }
    if(!pos) {
        cout<<"NONE\n";
        return 0;
    }
    
    // brute force the answer
    rep(i, n) rep(j, n) if(j != i) {
        if(mat[i][j].length() != Sz[i] + Sz[j]) {
            pos = 0;
            break;
        }
        rep(k, mat[i][j].length()) {
            if(k < Sz[i] and S[i][k] != mat[i][j][k]) pos = 0;
            if(k >= Sz[i] and S[j][k - Sz[i]] != mat[i][j][k]) pos = 0;
        }
    }
    if(!pos) {
        cout<<"NONE\n";
        return 0;
    }
    else {
        cout<<"UNIQUE\n";
        rep(i, n) cout<<S[i]<<'\n';
    }



    return 0;
}