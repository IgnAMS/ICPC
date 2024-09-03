#include<bits/stdc++.h>
using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef vector<ll> vl;
#define pb push_back

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        int n = s.length();
        ll A[n];
        rep(i, n) A[i] = bool(s[i] == '(') or (s[i] == ')');
        vl S0, S1;
        bool prev = bool(A[0] == 1);
        bool pos = 1;
        // S0: Vector que contiene los 0's 
        // S1: vector qeu contiene los 1's
        // rep(i, n) cout<<A[i]<<' '; cout<<'\n';
        // cout<<s<<'\n';
        rep(i, n) {
            // Evento de cerrar
            if(prev == 0 and A[i] == 1 and S1.size() >= 1 and S0.back() == 2) {
                prev = 1;
                S0.pop_back();
            }
            else if(prev == 1 and A[i] == 0 and S0.size() >= 1 and S1.back() == 2) {
                prev = 0;
                S1.pop_back();
            }
            // Evento de abrir
            else if(prev == 0 and A[i] == 1 and !S0.empty() and S0.back() == 1) {
                prev = 1;
                S1.pb(0);
            }
            else if(prev == 1 and A[i] == 0 and !S1.empty() and S1.back() == 1) {
                prev = 0;
                S0.pb(0);
            }
            // Mas eventos de abrir
            if(prev == 0 and A[i] == 0 and S0.empty()) {
                // cout<<"debi entrar aca\n";
                S0.pb(0);
            }
            else if(prev == 1 and A[i] == 1 and S1.empty()) {
                S1.pb(0);
            }
            else if(prev == 1 and A[i] == 0 and S0.empty()) {
                S0.pb(0);
                prev = 0;
            }
            else if(prev == 0 and A[i] == 1 and S1.empty()) {
                S1.pb(0);
                prev = 1;
            }
            
            // Evento de aumentar
            if(prev == 0 and A[i] == 0) {
                // cout<<"aumente aca\n";
                S0.back() += 1;
            }
            else if(prev == 1 and A[i] == 1) {
                S1.back() += 1;
            }

            // cout<<S0.size()<<' '<<S1.size()<<'\n';
            // for(auto u: S0) cout<<u<<' '; cout<<'\n';
            // for(auto u: S1) cout<<u<<' '; cout<<'\n';


            // if(!S1.empty()) cout<<S1.back()<<'\n';
            // if(!S0.empty()) cout<<S0.back()<<'\n';

            if(!S1.empty() and S1.back() > 2) { pos = 0; break; }
            if(!S0.empty() and S0.back() > 2) { pos = 0; break; }
        }
        if(pos) cout<<"Yes\n";
        else cout<<"No\n";

    }    


    return 0;
}

