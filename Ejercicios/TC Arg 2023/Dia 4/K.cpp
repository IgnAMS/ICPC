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
        int t; cin>>t;
        while(t--) {
            int n; cin>>n;
            vl A(n), B(n); 
            rep(i, n) cin>>A[i];
            rep(i, n) cin>>B[i];
            
            ll ans = -1e17;
            // PRECOMPUTAR PREFIJO
            ll sumA = 0, sumB = 0;
            ll prefA[n + 1], prefB[n + 1]; prefA[0] = 0, prefB[0] = 0;
            rep(i, n) {
                sumA += A[i], sumB += B[i];
                prefA[i + 1] = max(A[i], prefA[i] + A[i]);
                prefB[i + 1] = max(B[i], prefB[i] + B[i]);
            }

            // PRECOMPUTAR SUFIJO
            ll sufA[n + 1], sufB[n + 1]; sufA[n] = 0, sufB[n] = 0;
            for(int i = n - 1; i >= 0; i--) {
                sufA[i] = max(A[i], sufA[i + 1] + A[i]);
                sufB[i] = max(B[i], sufB[i + 1] + B[i]);
            }

            rep(i, n + 1) {
                ans = max({ans, sufA[i] + sumB, sufB[i] + sumA});
                ans = max({ans, prefA[i] + sumB, prefB[i] + sumA});
                ans = max({ans, prefA[i] + sufB[i], prefB[i] + sufA[i]});
                if(i) ans = max({ans, prefA[i], prefB[i]});
                if(i < n) ans = max({ans, sufA[i], sufB[i]});
            }
            ans = max({ans, prefA[n] + sufB[0], sufA[0] + prefB[n]});

            cout<<ans<<'\n';
        }

        return 0;
    }