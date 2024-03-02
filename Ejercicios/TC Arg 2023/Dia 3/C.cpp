#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define ll long long
#define vl vector<ll>

int main(){
    int n, m;
    vector<vector<ll>> d(26, vl());
    string s;
    cin >> n >> s;
    int cont = 1;
    for(auto it : s)
    {
        d[it - 'a'].push_back(cont);
        cont++;
    }
    cin >> m;

    rep(i, m)
    {
        string x;
        cin >> x;
        int maxi = 0;
        vl co(26, 0);
        for(auto it : x)
        {
            co[it-'a']++;
            
        }
        rep(i, 26)
        {
            if(co[i] > 0)
                maxi = max((ll)maxi, (ll)d[i][co[i]-1]);
        }
        cout << maxi << "\n";
    }
}