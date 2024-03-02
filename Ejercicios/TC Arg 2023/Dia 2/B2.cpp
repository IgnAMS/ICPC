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

int n, m, mn;
vector<string> M, aux, ans;


void solve(string S1, string S2) {
    ll curr = 0;
    rep(i, n) {
        int x = 0, y = 0;
        rep(j, m) {
            if(i & 1) x += (S1[j & 1] != M[i][j]);
            else x += (S2[j & 1] != M[i][j]);
            if(i & 1) y += (S1[(j + 1) & 1] != M[i][j]);
            else y += (S2[(j + 1) & 1] != M[i][j]);
        }
        if(x < y) {
            // Me conviene cambiar la fila por S[j & 1]
            rep(j, m) {
                if(i & 1) aux[i][j] = S1[j & 1];
                else aux[i][j] = S2[j & 1];
            }
            curr += x;
        }
        else {
            // Me conviene cambiar por S[(j + 1) & 1];
            rep(j, m) {
                if(i & 1) aux[i][j] = S1[(j + 1) & 1];
                else aux[i][j] = S2[(j + 1) & 1];
            }
            curr += y;
        }
    }
    if(curr < mn) {
        // cout<<"actualize por row en "<<S1<<", "<<S2<<'\n';
        mn = curr;
        ans = aux;
    }

    curr = 0;
    rep(j, m) {
        int x = 0, y = 0;
        rep(i, n) {
            if(j & 1) x += (S1[i & 1] != M[i][j]);
            else x += (S2[i & 1] != M[i][j]);
            if(j & 1) y += (S1[(i + 1) & 1] != M[i][j]);
            else y += (S2[(i + 1) & 1] != M[i][j]);
        }
        if(x < y) {
            // Me conviene cambiar la fila por S[i & 1]
            rep(i, n) {
                if(j & 1) aux[i][j] = S1[i & 1];
                else aux[i][j] = S2[i & 1];
            }
            curr += x;
        }
        else {
            // Me conviene cambiar por S[(i + 1) & 1];
            rep(i, n) {
                if(j & 1) aux[i][j] = S1[(i + 1) & 1];
                else aux[i][j] = S2[(i + 1) & 1];
            }
            curr += y;
        }
    }
    if(curr < mn) {
        // cout<<"actualize por column en "<<S1<<", "<<S2<<'\n';
        mn = curr;
        ans = aux;
    }
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m; mn = 1e6;
    string X = ""; rep(i, m) X += '.';
    M.resize(n), aux.assign(n, X), ans.assign(n, X);
    rep(i, n) cin>>M[i];
    vector<char> S = {'A', 'G', 'C', 'T'};
    do{
        // for(auto u: S) cout<<u<<' '; cout<<'\n';
        string S1 = "";
        S1 += S[0]; S1 += S[1];
        string S2 = "";
        S2 += S[2]; S2 += S[3];
        solve(S1, S2);
    } while(next_permutation(S.begin(), S.end()));
    // cout<<mn<<'\n';
    rep(i, n) cout<<ans[i]<<'\n';



    return 0;
}