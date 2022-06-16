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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // 0: p, 1: q, 2: r, 3: s
    ll V[4] = {'s', 'r', 'q', 'p'};
    ll H[4] = {'q', 'p', 's', 'r'};

    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        vi last(4, -1);
        vi S(s.length());
        rep(i, S.size()) {
            if(s[i] == 'p') last[0] = i, S[i] = 0;
            if(s[i] == 'q') last[1] = i, S[i] = 1;
            if(s[i] == 'r') last[2] = i, S[i] = 2;
            if(s[i] == 's') last[3] = i, S[i] = 3;
        }
        vector<string> Ans(4, s);
        // U
        if(max(last[2], last[3]) != -1) {
            repx(i, max(last[2], last[3]), s.size()) Ans[0][i] = char(V[S[i]]);
            
        }
        else Ans[0] = "<none>";

        // D
        if(max(last[0], last[1]) != -1) {
            repx(i, max(last[0], last[1]), s.size()) Ans[1][i] = char(V[S[i]]);
        }
        else Ans[1] = "<none>";

        // L
        if(max(last[1], last[2]) != -1) {
            repx(i, max(last[1], last[2]), s.size()) Ans[2][i] = char(H[S[i]]);
        }
        else Ans[2] = "<none>";
        
        // R
        if(max(last[0], last[3]) != -1) {
            repx(i, max(last[0], last[3]), s.size()) Ans[3][i] = char(H[S[i]]);
        }
        else Ans[3] = "<none>";

        rep(i, 4) cout<<Ans[i]<<" \n"[i == 3];

    }





    return 0;
}