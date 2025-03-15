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



string to_str(int x, int n) {
    string res = "";
    if(x == 0) return "a";
    while(x) {
        if(x % n >= 26) res += 'A' + ((x % n) - 26);
        else res += 'a' + (x % n);
        x /= n;
    }
    return res;
}

ll to_digit(char c) {
    if('A' <= c and c <= 'Z') return c - 'A' + 26;
    return c - 'a'; 
} 

char to_char(int x) {
    if(x >= 26) return 'A' + (x - 26);
    return 'a' + x;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // A[0] = 0, ..., A[n - 1] = 0
    // A[n] = 0, A[n + 1] = 1, A[n + 2] = 2, A[n + i] = i, ..., A[2n - 1] = n - 1
    // A[2n] = 0, A[2n + 1] = 2, A[2n + 2] = 4, A[2n + 3] = 6, ..., 
    repx(n, 6, 30) {
        multiset<string> S, S2;
        rep(i, n) {
            rep(j, n) S.insert(to_str(i * j, n)), S2.insert(to_str(i * j, n));
        }
        
        cout<<"\n\nNUEVA ITERACION CON: "<<n<<'\n';

        set<string> mp[3][2 * n], mp2[3][2 * n];
        for(auto u: S) {
            mp[u.length()][S.count(u)].insert(u);
            mp2[u.length()][S.count(u)].insert(u);
        }

        repx(len, 1, 3) rep(cant, 2 * n) if(!mp[len][cant].empty()) {
            for(auto x: mp[len][cant]) cout<<x<<' '<<cant<<'\n'; cout<<'\n';
        }
        cout<<'\n';

        ll cont = 0, iter = 0;
        vl Digit(n, -1);
        while(cont < n * n and iter++ < 100000) {
            vector<string> Elim;
            rep(i, n) if(Digit[i] != -1) cout<<to_char(i)<<' '<<to_char(Digit[i])<<'\n'; cout<<'\n';
            // O(n^2)
            repx(len, 1, 3) rep(cant, 2 * n) {
                for(auto str: mp[len][cant]) {
                    ll det = 1;
                    for(auto c: str) if(Digit[to_digit(c)] == -1) det = 0;
                    if(det) {
                        Elim.pb(str);
                        cont += cant;
                    }
                }
            }

            for(auto str: Elim) {
                string s2 = "";
                for(auto c: str) s2 += to_char(Digit[to_digit(c)]);
                cout<<"elimino a "<<str<<' '<<s2<<" ya que ya estan 100 definidos\n";
                mp[str.length()][S.count(str)].erase(str);
                mp2[s2.length()][S2.count(s2)].erase(s2);
            }

            repx(len, 1, 3) rep(cant, 2 * n) if(!mp[len][cant].empty()) {
                for(auto x: mp[len][cant]) cout<<x<<' '<<cant<<'\n'; cout<<'\n';
            }
            cout<<'\n';

            
            bool pos = (cont >= n * n);
            // O(n)
            repx(len, 1, 3) rep(cant, 2 * n) {
                if(mp[len][cant].size() == 1) {
                    string s1 = *mp[len][cant].begin();
                    string s2 = *mp2[len][cant].begin();
                    
                    rep(i, s1.size()) {
                        Digit[to_digit(s1[i])] = to_digit(s2[i]);
                    }
                    pos = 1;
                }
            }
            if(!pos) {
                cout<<"NO SE PUEDE TERMINAR U.U\n";
                return 0;
            }
        }
    }



    return 0;
}