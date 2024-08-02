#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back

void printerror(int i, int j, int i2, int j2, char c){
    cout << i+1 << ":" << j+1 << ": warning: shadowed declaration of " << c << ", the shadowed position is " << i2+1 << ":" << j2+1 << "\n";
}

void solve(){
    vector<vector<array<int, 3>>> occ2(26, vector<array<int, 3>>());
    vector<int> occ(26, -1), cnt(26, 0);
    int n;
    cin >> n;
    int fcnt = 0;
    string xd, s;
    getline(cin, xd);
    rep(_, n){
        //s.clear();
        getline(cin, s);
        //cout<<"hola: " << s << " " << s.size() <<  "\n";
        for(int i = 0, iff = 0; i<s.size(); ++i, ++iff){
            //cout << _ << " " << i << " " << s[i] << "\n";
            //while(!isalpha(s[i])) i++;
            if(!isalpha(s[i]) && !(s[i] == '{') && !(s[i] == '}') && !isblank(s[i])){
                i++;
                continue;
            }
            if(isalpha(s[i])){
                for(int j = occ2[s[i]-'a'].size()-1; j>=0; --j){
                    if(occ2[s[i]-'a'][j][2] < fcnt){
                        printerror(_, iff, occ2[s[i]-'a'][j][0], occ2[s[i]-'a'][j][1], s[i]);
                        break;
                    }
                }
                occ2[s[i]-'a'].push_back({_, i, fcnt});
                // occ[s[i]-'a'] = 1;
                // occ2[s[i]-'a'] = {_,i};
                // cnt[s[i]-'a'] = fcnt;
            }else if(s[i] == '{'){
                fcnt++;
            }else if(s[i] == '}'){
                rep(x, 26){
                    vector<array<int, 3>> ff;
                    for(auto val : occ2[x]){
                        if(val[2] < fcnt){
                            ff.push_back(val);
                        }
                    }
                    occ2[x] = ff;
                }
                fcnt--;
            }
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}

