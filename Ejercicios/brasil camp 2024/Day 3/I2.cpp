    #pragma GCC optimize("Ofast")
    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define ll long long 
    #define ar array
    #define rep(i, n) for(int i = 0; i<(int)n; ++i)
    #define vl vector<ll> 
     
    const int mxN = 2e5+5, M = 1e9+7;
     
    struct RH{
        // choose base B random to avoid hacks 33 37 41
        // randomize V(s[i])
        int B = 1777771, M[2] = {999727999, 1070777777}, P[2] = {325255434, 10018302};
        vl H[2], I[2];
        RH(string &s){
            int N = s.size(); rep(k, 2){
                H[k].resize(N + 1), I[k].resize(N + 1);
                H[k][0] = 0, I[k][0] = 1; ll b = 1;
                rep(i, N + 1) if (i){
                    H[k][i] = (H[k][i - 1] + b * s[i - 1]) % M[k];
                    I[k][i] = (1LL * I[k][i - 1] * P[k]) % M[k];
                    b = (b * B) % M[k];
                }
            }
        }
        ll get(int l, int r){ // inclusive - exclusive
            ll h0 = (H[0][r] - H[0][l] + M[0]) % M[0];
            h0 = (1LL * h0 * I[0][l]) % M[0];
            ll h1 = (H[1][r] - H[1][r] + M[1]) % M[1];
            h1 = (1LL * h1 * I[1][l]) % M[1];
            return (h0 << 32) | h1;
        }
    };
     
    int main(){
    #ifdef _DEBUG
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", " w", stdout);
    #endif
        std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
     
        string s, s1, s2;
        cin >> s >> s1 >> s2;
        RH rh(s), f1(s1), f2(s2);
     
        set<ll> ans;
        for(int i = 0; i<(int)s.size() - (int)s1.size() + 1; ++i){
            for(int j = i+(int)s1.size() - (int)s2.size(); j<(int)s.size() - (int)s2.size() + 1; ++j){
                if(j < i) continue;
                if(rh.get(i, i+s1.size()) == f1.get(0, s1.size()) && rh.get(j, j+s2.size()) == f2.get(0, s2.size())){
                    ans.insert(rh.get(i, j+1));
                }
            }
        }
        cout << ans.size() << "\n";
    }