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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<vi> S;
    vi D(n), T(n);
    rep(i, n) {
        ll t, d; cin>>t>>d;
        T[i] = t, D[i] = d;
        S.push_back({d, t, i});
    }
    sort(S.begin(), S.end());
    vi Acc(n, 0);
    vi Sol(n, 0), Ind(n, 0);
    rep(i, n) Acc[i] = S[i][1] + (i > 0? Acc[i - 1]: 0);
    rep(i, n) {
        if(Acc[i] > S[i][0]) {
            cout<<"*\n";
            return 0;
        }
        Sol[i] = S[i][2];
        Ind[S[i][2]] = i;
    }
    vi V(n, 0);
    rep(i, n) {
        vi Mn(n + 1, 100000000000000LL); 
        repx(j, i, n) Mn[j] = D[Sol[j]] - Acc[j];
        repx(j, i + 1, n) Mn[j] = min(Mn[j], Mn[j - 1]);
        rep(j, Sol[i]) if(!V[j] and Ind[j] > i and T[j] <= Mn[Ind[j] - 1]) {
            V[j] = 1;
            for(int k = Ind[j] - 1; k >= i; k--) {
                Acc[k] += T[j] - T[Sol[k]];
                Ind[Sol[k]]++;
                Ind[Sol[k + 1]]--;
                swap(Sol[k], Sol[k + 1]);
            } 
            break;
        }
    }
    rep(i, n) cout<<Sol[i] + 1<<' '; cout<<'\n';


    return 0;
}