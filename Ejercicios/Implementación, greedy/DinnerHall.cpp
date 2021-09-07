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


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    int cont = 0;
    while(cin>>n and n){
        // if(++cont == 48) cout<<"\n\nn: "<<n<<'\n';
        set<ii> S;
        int e = 0, x = 0, q = 0; 
        rep(i, n){
            string line, com; cin>>line>>com;
            ll hora = (
                (line[0] * 10 + line[1] - '0' * 11) * 3600 + 
                (line[3] * 10 + line[4] - '0' * 11) * 60 + 
                line[6] * 10 + line[7] - '0' * 11 
            );
            if(com == "E") { S.insert(ii(hora, 0)); e++; }
            else if(com == "?") { S.insert(ii(hora, 1)); q++; }
            else { S.insert(ii(hora, 2)); x++; }
        }
        // if(cont == 48) { for(auto u : S) cout<<u.ss<<'\n'; cout<<"\n\n"; }
        ll ans = 0;
        ll curr = 0;
        for(auto u: S){
            if(u.ss == 0) curr++, e--;
            else if(u.ss == 2) curr--, x--;
            else{
                if(curr + 1 <= (q-1) + x - e) curr++; // si tengo para cerrar, abro
                else curr--; // si no puedo abrir, cierro
                q--;
            }
            // if(cont == 48) cout<<curr<<'\n';
            ans = max(ans, curr);
        }
        cerr<<ans<<'\n';
        cout<<ans<<'\n';
    }

    return 0;
}