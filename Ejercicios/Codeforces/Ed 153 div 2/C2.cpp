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
            vl A(n); rep(i, n) cin>>A[i];
            if(n == 1) {
                cout<<0<<'\n';
                continue;
            }
     
            ll ans = 0;
            
            int i = 0;
            while(i < n - 1 and A[i] >= A[i + 1]) i++;
            ll mn = A[i];
            i++;
            ll mn2 = 1e10;
            while(i < n) {
                if(A[i] > mn and A[i] <= mn2) {
                    ans++;
                }
                if(A[i] < mn) {
                    mn = A[i];
                    i++;
                    continue;    
                } 
                mn2 = min(mn2, A[i]);
                i++;
            }
            cout<<ans<<'\n';
        }
        return 0;
    }