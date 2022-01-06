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

const db PI = acos(-1.0L);
const db EPS = 1e-12;

bool inCirc(ii& p, double r, bool diag=0){
    return p.ff * p.ff + p.ss * p.ss - EPS <= r * r * (diag? 2: 1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<ii> P(n); rep(i, n) {
        cin>>P[i].ff>>P[i].ss;
        if(P[i].ff >= 0 and P[i].ss >= 0) continue;  // C1
        else if(P[i].ff <= 0 and P[i].ss <= 0) P[i] = {-P[i].ff, -P[i].ss}; // C3
        else if(P[i].ff >= 0 and P[i].ss <= 0) P[i] = {-P[i].ss, P[i].ff}; // C4
        else if(P[i].ff <= 0 and P[i].ss >= 0) P[i] = {P[i].ss, -P[i].ff}; // C2
    }
    double l = 0, r = 1*1e10;
    rep(_, 100){
        double lado = (l + r) / 2; // diagonal del cuadrado
        // dentro de la circ inscrita entonces es imposible, bajar
        bool flag = 0;
        rep(i, n) if(inCirc(P[i], lado)) flag = 1;
        if(flag) { r = lado; continue; }
        
        set<pair<double, int>> S; // ang1, entrada(1) o salida(0)
        int a = 0, b = 0;
        rep(i, n) if(inCirc(P[i], lado, 1)){
            double gamma;
            if(P[i].ff == 0) gamma = 0;
            else gamma = atan(double(P[i].ss) / double(P[i].ff));
            double alpha = acos(lado / sqrt(P[i].ff * P[i].ff + P[i].ss * P[i].ss));
            a++;
            // cout<<(gamma - alpha) * 180.0 / PI<<' '<<(gamma + alpha) * 180.0 / PI<<'\n';
            double x = gamma - alpha;
            double y = gamma + alpha;
            while(x <= 0) x += 0.5 * PI;
            while(x >= 0.5 * PI) x -= 0.5 * PI;
            while(y >= 0.5 * PI) y -= 0.5 * PI;
            // cout<<x * 180.0 / PI<<" "<<y * 180.0 / PI<<'\n';
            if(y < x) b++;
            S.insert({x, 0});
            S.insert({y, 1});
        }
        int cont = b;
        bool pos = 0;
        if(b == a) pos = 1;
        for(auto it = S.begin(); it != S.end(); it++){
            auto u = *it;
            // if(-EPS <= u.ff and u.ff - EPS <= PI / 2.0 and cont == 0) pos = 1;
            if(u.ss == 0) cont++;
            else cont--;
            if(cont == a) pos = 1;
            // cout<<u.ff * 180.0 / PI<<' '<<u.ss<<'\n';
            // cout<<(next(it) == S.end())<<' '<<u.ff * 180.0 / PI<<'\n';
            // if(next(it) == S.end() and u.ff - EPS <= PI / 2.0) pos = 1;
        }
        // if(S.size() == 0) pos = 1;
        // cout<<"el lado mide "<<lado<<" y es "<<pos<<" hacer un cuadrado\n\n";
        if(pos) l = lado;
        else r = lado;
    }
    cout<<(l + r) / (2.0) * 8<<'\n';

    return 0;
}