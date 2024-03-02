    #pragma GCC optimize("Ofast")
    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define ll long long 
    #define ar array
    #define rep(i, n) for(int i = 0; i<(int)n; ++i)
    #define vl vector<ll> 
     
    const int mxN = 2e5+5, M = 1e9+7;
     
     
     
    int main(){
    #ifdef _DEBUG
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", " w", stdout);
    #endif
        std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
     
        string s, s1, s2;
        cin >> s >> s1 >> s2;
        vector<int> v1, v2;
        rep(i, s.size()){
            if(i+s1.size() <= (int)s.size() && s.substr(i, s1.size()) == s1) v1.push_back(i);
            if(i+s2.size() <= (int)s.size() && s.substr(i, s2.size()) == s2) v2.push_back(i);
        }
        
        ll ans = 0;
        rep(i, v1.size()){
            rep(j, v2.size()){
                if(v1[i] <= v2[j] and v1[i] + s1.size() <= v2[j] + s2.size()) ans++;
            }
        }
        cout << ans << "\n";
    }