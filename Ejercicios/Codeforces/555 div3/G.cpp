#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include<algorithm>
#include<numeric>
#include <unordered_map>
#include <cmath>
#include<set>
#include<array>
using namespace std;
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -std=c++17 -O2 G.cpp && time ./a.out <input.txt> output.txt

#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define repx(i, a, b) for(int i = (int)a; i < (int)b; ++i)
typedef pair<ll, ll> pll; 
typedef vector<int> vi;

const int mxN = 201;
int n, m;
int A[mxN][mxN];

vector<vector<pair<vi, vi>>> accumulate(int sign) {
    vector<vector<pair<vi, vi>>> Zeros(n);
    
    // first case: match the case
    {
        rep(b, 2) {
            vi invcol(m, 0);
            rep(j, m) {
                invcol[j] = (A[0][j] ^ sign ^ b) != 0;
            }
            Zeros[0].push_back({invcol, {b}});
        }
    }

    // there should be at most 2 solutions to zeros at each level
    repx(i, 1, n) {
        rep(b, 2) {
            for(auto& [invcol, bs] : Zeros[i-1]) {
                bool pos = 1;
                rep(j, m) if((A[i][j] ^ sign ^ b) != invcol[j]) pos = 0;
                if(pos) {
                    vi newb = bs; newb.push_back(b);
                    Zeros[i].push_back({invcol, newb});
                }
            }
        }
    }

    return Zeros;
}

bool validaterow(int i, bool b, vi& invcol) {
    bool pos = 1;
    bool firstone = 0;
    rep(j, m) {
        if((A[i][j] ^ b ^ invcol[j]) == 1) firstone = 1;
        if(firstone == 1 and (A[i][j] ^ b ^ invcol[j]) == 0) pos = 0;
    }
    return pos;
}

void printans(vi bs, int b, vi revbs, vi& invcol) {
    cout<<"YES\n";
    // rows
    for(auto it = bs.begin(); it != bs.end(); it++) cout<<*it;
    cout<<b;
    for(auto it = revbs.rbegin(); it != revbs.rend(); it++) cout<<*it;
    cout<<'\n';

    // cols
    rep(j, m) cout<<invcol[j]; cout<<'\n';
}


int main() {
    cin>>n>>m;
    rep(i, n) rep(j, m) cin>>A[i][j];
    if(n == 1) {
        cout<<"YES\n";
        cout<<0<<'\n'; // rows
        rep(i, m) cout<<A[0][i]; cout<<'\n';
        return 0;
    }

    // Zeros it is of size n * n * m * 2 = 8 * 10^6
    auto Zeros = accumulate(0);
    reverse(A, A+n); // reverse the columns
    auto Ones = accumulate(1);
    reverse(Ones.begin(), Ones.end());
    reverse(A, A+n);
    
    // case of row 0:
    cerr<<"first case:\n";
    for(auto& [invcol, revbs]: Ones[1]) {
        rep(b, 2) {
            bool pos = validaterow(0, b, invcol);
            if(pos) {
                printans({}, b, revbs, invcol);
                return 0;
            }
        }
    }

    // case of row N-1:
    cerr<<"second case:\n";
    for(auto& [invcol, bs]: Zeros[n-2]) {
        rep(b, 2) {
            bool pos = validaterow(n-1, b, invcol);

            if(pos) {
                printans(bs, b, {}, invcol);
                return 0;
            }
        }
    }


    // otherwise
    cerr<<"third case:\n";
    repx(i, 1, n - 1) {
        // atmost 4 comparisons
        for(auto [invcol, bs]: Zeros[i-1]) for(auto [invcol2, revbs]: Ones[i+1]) {
            bool sorry_next = 0;
            rep(j, m) if(invcol[j] != invcol2[j]) sorry_next = 1;
            if(sorry_next) continue;
            rep(b, 2) {
                bool pos = validaterow(i, b, invcol);
                if(pos) {
                    printans(bs, b, revbs, invcol);
                    return 0;
                }
            }
        }
    }

    cout<<"NO\n";
}