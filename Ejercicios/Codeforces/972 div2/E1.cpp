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

int l, n, m; 
int A[301];
int M[303][303];
short DP[303][303][2]; 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>l>>n>>m;
        A[0] = 0;
        rep(i, l) cin>>A[i + 1];
        rep(i, n) rep(j, m) cin>>M[i + 1][j + 1];

        rep(i, n + 2) rep(j, n + 2) rep(b, 2) DP[i][j][b] = 0;
        DP[0][0][0] = 1;
        bool not_pos = 0;
        repx(c, 1, n + 1) {
            bool finded = 0;
            repx(i, 1, n + 1) {
                bool oc = 0;
                bool oc2 = DP[0][0][0] or DP[0][1][0] or DP[1][0];
                repx(j, 1, m + 1) {
                    if(DP[i - 1][j - 1][0]) oc = 1;
                    if(DP[i][j][0]) oc2 = 1;
                    if(M[i][j] == A[c] and oc == 0 and oc2 == 1) {
                        cout<<"el elemento "<<A[c]<<" fue encontrado en una posicion imposible ;c\n";
                        if(c % 2 == 1) cout<<"T\n";
                        else cout<<"N\n";
                        finded = 1;
                        not_pos = 1;
                        break;
                    }
                    if(M[i][j] == A[c] and oc == 1) {
                        finded = 1;
                        DP[i][j][1] = 1;
                    }
                }
                if(not_pos) break;
                repx(j, 1, m + 1) DP[i][j][0] = DP[i][j][1], DP[i][j][1] = 0;
            }
            if(!finded) {
                if(c % 2 == 1) cout<<"T\n";
                else cout<<"N\n";
                break;
            }
            if(not_pos) break;
        }

    }

    return 0;
}