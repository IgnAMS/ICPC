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
int low[2], high[2];

void shift(string& a, int k) {
    if(k > 0) {
        // Debo alterar los bits de mi derecha
        // cout<<a<<'\n';
        // rep(i, n) cout<<(i + k < n? a[i + k]: '0'); cout<<'\n';
        for(int i = 0; i + k < n; i++) {
            if(a[i] == '1' and a[i + k] == '1') a[i] = '0';
            else if(a[i] == '0' and a[i + k] == '1') a[i] = '1';
        }

        low[0] = n, high[0] = 0;
        rep(i, n) {
            if(a[i] != '0') low[0] = n - i - 1, high[0] = max(high[0], n - i - 1);
        }
    }
    else {
        // k < 0
        // cout<<a<<'\n';
        // rep(i, n) cout<<(i + k >= 0? a[i + k]: '0'); cout<<'\n'; 
        for(int i = n - 1; i + k >= 0; i--) {
            if(a[i] == '1' and a[i + k] == '1') a[i] = '0';
            else if(a[i] == '0' and a[i + k] == '1') a[i] = '1';
        }
        // cout<<a<<"\n\n";

        low[0] = n, high[0] = 0;
        rep(i, n) {
            if(a[i] != '0') low[0] = n - i - 1, high[0] = max(high[0], n - i - 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        string a, b; cin>>a>>b;
        ll zero[] = {1, 1};
        rep(i, n) {
            if(a[i] != '0') zero[0] = 0;
            if(b[i] != '0') zero[1] = 0;
        }
        if(zero[0] != zero[1]) {
            cout<<"-1\n";
            continue;
        }
        if(zero[0] == 1) {
            cout<<"0\n";
            continue;
        }

        low[0] = low[1] = n, high[0] = high[1] = 0;
        rep(i, n) {
            if(a[i] != '0') low[0] = n - i - 1, high[0] = max(high[0], n - i - 1);
            if(b[i] != '0') low[1] = n - i - 1, high[1] = max(high[1], n - i - 1); 
        }
        vl Ans;
        if(high[0] < low[1]) {
            Ans.pb(low[1] - high[0]);
            shift(a, low[1] - high[0]);
        }
        // elimino todo lo que este abajo de low[1]
        for(int i = low[1] - 1; i >= 0; i--) {
            if(a[n - i - 1] == '1') {
                // shifteo a la derecha
                Ans.pb(-high[0] + i);
                shift(a, -high[0] + i);
            }
        }

        if(low[0] > low[1]) {
            // shifteo a la derecha
            Ans.pb(-low[0] + low[1]);
            shift(a, -low[0] + low[1]);
        }

        repx(i, low[1], n) {
            if(a[n - i - 1] != b[n - i - 1]) {
                // shifteo a la izquierda
                Ans.pb(i - low[0]);
                shift(a, i - low[0]);
            }
        }
        cout<<Ans.size()<<'\n';
        if(Ans.size()) {
            for(auto u: Ans) cout<<u<<' '; cout<<'\n';
        }
    }





    return 0;
}