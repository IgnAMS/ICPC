    #pragma GCC optimize("Ofast")
    #pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

    int main(){
        ios::sync_with_stdio(0); cin.tie(0);
        int n; cin>>n;
        vl V(n); rep(i, n) cin>>V[i];
        vl T(n); rep(i, n) cin>>T[i];

        ll acc = 0;
        ll Acc[n + 1]; Acc[0] = 0; 
        multiset<ll> S;
        rep(i, n) {
            S.insert(Acc[i]+ V[i]);
            ll ans = 0;
            Acc[i + 1] = T[i] + Acc[i];
            while(!S.empty() and Acc[i + 1] >= *S.begin()) {
                ans += *S.begin() - Acc[i];
                S.erase(S.begin());
            }
            ans += ll(S.size()) * T[i];
            cout<<ans<<" \n"[i == n - 1];
        }

        return 0;
    }