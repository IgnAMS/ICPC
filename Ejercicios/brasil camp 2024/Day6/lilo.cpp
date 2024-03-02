#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ar array
#define rep(i, n) for(int i = 0; i<(int)n; ++i)

const int mxN = 2e5+5, M = 1e9+7;


int main(){
#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", " w", stdout);
#endif
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    if(n == 1){
        string ans = "";
        rep(i, s.size()){
            ans += 'A';
        }
        cout << ans << "\n";
    }else if(n == 2){
        rep(_, 3000){
            rep(i, s.size()){
                if(s[i] != '.'){
                    if(i && s[i-1] == '.'){
                        if(s[i] == 'A')s[i-1] = 'B';
                        else s[i-1] = 'A';
                    }
                    if(i < s.size() && s[i+1] == '.'){
                        if(s[i] == 'A')s[i+1] = 'B';
                        else s[i+1] = 'A';
                    }
                }
            }
        }
        cout << s << "\n";
    }else{
        rep(i, s.size()){
            if(s[i] == '.' && (i==0? 1 : s[i-1] != 'A') && (i==(int)s.size()-1? 1 : s[i+1] != 'A')) s[i] = 'A';
            else if(s[i] == '.' && (i==0? 1 : s[i-1] != 'B') && (i==(int)s.size()-1? 1 : s[i+1] != 'B')) s[i] = 'B';
            else if(s[i] == '.' && (i==0? 1 : s[i-1] != 'C') && (i==(int)s.size()-1? 1 : s[i+1] != 'B')) s[i] = 'C';
        }
        cout << s << "\n";
    }
}