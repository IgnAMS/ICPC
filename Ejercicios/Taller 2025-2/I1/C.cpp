#pragma GCC optimize("Ofast")
#include<vector>
#include<iostream>
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

// 2^10 = 10^3
// DP[i][x][d1][d2][d3][d4][d5][d6][d7][d8][d9][not_zero]
int digits;
int n;
const int max_bm = 1<<13;

ll DP[10][max_bm][2];

ll dp(int i, int pot, int bm, bool not_zero) {
    // cout<<n<<" "<<digits<<"\n";
    // cout<<i<<" "<<pot<<" "<<bm<<" "<<not_zero<<"\n";
    if(i == digits and not_zero and (bm>>digits) == 0) return 1;
    if(i == digits) return 0;
    if(DP[i][bm][not_zero] != -1) return DP[i][bm][not_zero];
    ll ans = 0;
    int curr_digit = (n / pot) % 10;
    int carry_digit = bool(bm & (1<<i));
    rep(j, 10) {
        int new_dig = (carry_digit + j) % 10;
        int new_carry = (carry_digit + j) >= 10;
        if(new_dig == curr_digit) {
            ans += dp(i + 1, pot * 10, bm + (new_carry<<(i+2)), not_zero);
        }
        else if(new_dig < curr_digit) {
            ans += dp(i + 1, pot * 10, bm + (new_carry<<(i+2)), 1);
        }
        else {
            // new_dig > curr_digit
            ans += dp(i + 1, pot * 10, bm + (1<<(i+2)), 1);
        }
    }
    DP[i][bm][not_zero] = ans;
    return ans;
}


void solve() {
    cin>>n;
    digits = 0;
    int aux = n;
    while(aux) digits++, aux /= 10;
    // cout<<9 * max_bm * 2<<"\n";
    rep(i, digits) rep(j, max_bm) rep(k, 2) DP[i][j][k] = -1;
    cout<<dp(0, 1, 0, 0) - 1<<"\n";
    // cout<<"termine "<<n<<"\n\n";
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; 
    while(t--) solve();
    return 0;
}