#pragma GCC optimize("Ofast")
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
// g++ -O2 D.cpp && time ./a.out < input.txt > output.txt


int sq(int x) { return sqrt(x); }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, t; cin>>n>>t;
    vi A(n); rep(i, n) cin>>A[i];
    vector<vi> E;
    ll sqr = sqrt(n);
    rep(i, t) {
        int l, r; cin>>l>>r; l--, r--;
        E.push_back({l / sqr, r, l, r, i}); // 2: l, 3: r, 4: i
    }
    sort(E.begin(), E.end(), [&](const vi& a, const vi& b) {
        return sq(a[2]) < sq(b[2]) or (sq(a[2]) == sq(b[2]) and sq(a[3]) < sq(b[3]));
    });

    ll l = E[0][2], r = E[0][3];
    vi F(1000001, 0);
    ll curr = 0;
    vi Ans(t, 0);
    repx(i, l, r + 1) {
        F[A[i]]++;
        curr += F[A[i]] * F[A[i]] * A[i] - ((F[A[i]] - 1) * (F[A[i]] - 1) * A[i]);
        
    }
    Ans[E[0][4]] = curr;
    repx(i, 1, t) {
        while(E[i][2] > l) {
            F[A[l]]--;
            curr += F[A[l]] * F[A[l]] * A[l] - ((F[A[l]] + 1) * (F[A[l]] + 1) * A[l]);
            l++;
        }
        while(E[i][2] < l) {
            l--;
            F[A[l]]++; 
            curr += F[A[l]] * F[A[l]] * A[l] - ((F[A[l]] - 1) * (F[A[l]] - 1) * A[l]);
        }
        while(E[i][3] > r) {
            r++;
            F[A[r]]++;
            curr += F[A[r]] * F[A[r]] * A[r] - ((F[A[r]] - 1) * (F[A[r]] - 1) * A[r]);
        }
        while(E[i][3] < r) {
            F[A[r]]--;
            curr += F[A[r]] * F[A[r]] * A[r] - ((F[A[r]] + 1) * (F[A[r]] + 1) * A[r]);
            r--;
        }
        Ans[E[i][4]] = curr;
        l = E[i][2], r = E[i][3];
    }
    rep(i, t) cout<<Ans[i]<<'\n';
    
    



    return 0;
}