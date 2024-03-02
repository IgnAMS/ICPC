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


ll A[35], Div[3];
vl DP[35];
ll n, k;
const ll INF = 1e10;

// vl DP[35][35][35];
// vl dp(ll ind, ll a, ll b, ll c) {
//     if(ind == -1) {
//         return {3 * k, 0, 1};
//     }
//     vl& ans = DP[a][b][c];
//     if(ans[0] != -1) return ans;
//     
//     ans = {INF, 100000, 1};
//     rep(h, 3) {
//         ll nexta = a - (h == 0), nextb = b - (h == 1), nextc = c - (h == 2);
//         if(nexta == -1 or nextb == -1 or nextc == -1) continue;
// 
//         vl aux = dp(ind - 1, nexta, nextb, nextc);
//         ll newnum = A[ind] * aux[2] + aux[1] * Div[h];
//         ll newdiv = Div[h] * aux[2];
//         
//         ll g = __gcd(newnum, newdiv);
//         newnum /= g, newdiv /= g; 
//         ll newcost = abs((3 * k) * newdiv - newnum);
//         if(newcost * ans[2] < ans[0] * newdiv) {
//             ans = {newcost, newnum, newdiv};
//         }
//         else if(newcost * ans[2] == ans[0] * newdiv and newnum * ans[2] < newdiv * ans[1]) {
//             ans = {newcost, newnum, newdiv};
//         }
//     }
//     return ans;
// }


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    rep(i, n) cin>>A[i];
    
    ll cont = 0;
    vl ans = {INF, 100000, 1};
    vl borde = {3 * k, 0, 1};

    repx(a, 1, n + 1) repx(b, 1, n + 1) repx(c, 1, n + 1) if(a + b + c == n) {     
        cont += 100000;
        Div[0] = a, Div[1] = b, Div[2] = c;

        rep(_, 30000) {
            random_shuffle(A, A + n);

            int n1 = a, n2 = b, n3 = c;
            rep(ind, n) {
                vl& curr = DP[ind];
                curr = {INF, 100000, 1};
                // if(ind == -1) curr = borde;
                
                rep(h, 3) {
                    if(n1 == 0 and h == 0) continue;
                    else if(h == 0) n1--;
                    
                    if(n2 == 0 and h == 1) continue;
                    else if(h == 1) n2--;
                    if(h == 2) n3--;


                    vl aux = ind == 0? borde: DP[ind - 1];
                    ll newnum = A[ind] * aux[2] + aux[1] * Div[h];
                    ll newdiv = Div[h] * aux[2];
                    
                    ll g = __gcd(newnum, newdiv);
                    newnum /= g, newdiv /= g; 
                    ll newcost = abs((3 * k) * newdiv - newnum);
                    if(newcost * curr[2] < curr[0] * newdiv) {
                        curr = {newcost, newnum, newdiv};
                    }
                    else if(newcost * curr[2] == curr[0] * newdiv and newnum * curr[2] < newdiv * curr[1]) {
                        curr = {newcost, newnum, newdiv};
                    }
                    break;
                }
            }

            vl aux = DP[n - 1];
            if(aux[0] * ans[2] < ans[0] * aux[2]) {
                ans = aux;
            }
            else if(aux[0] * ans[2] == ans[0] * aux[2] and aux[1] * ans[2] < aux[2] * ans[1]) {
                ans = aux;
            }   
            // cout<<aux[0]<<' '<<aux[1]<<' '<<aux[2] * 3<<'\n';
        }
    }

    // ll mxcont = 0;
    // repx(n, 1, 34) {
    //     cont = 0;
    //     repx(a, 1, n + 1) repx(b, 1, n + 1) repx(c, 1, n + 1) if(a + b + c == n) {     
    //         cont += 100000;
    //     }
    //     mxcont = max(mxcont, cont);
    // }
    


    ll g = __gcd(ans[1], ans[2] * 3);
    cout<<ans[1] / g<<'/'<<ans[2] * 3 / g<<'\n';
    // cout<<mxcont<<'\n';


    return 0;
}