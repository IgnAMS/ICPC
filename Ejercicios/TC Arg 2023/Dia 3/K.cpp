#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define ll long long
#define vl vector<ll>

int main() {
    int n;

    cin >> n;
    rep(i, n)
    {
        string s;
        cin >> s;
        
        bool flag = 0;
        int beg = s[0] - 'a'+1, endd = s[s.size()-1] - 'a'+1;
        
        if(endd < beg) {
            reverse(s.begin(), s.end());
            swap(beg, endd);
            flag = 1;
        }

        vl freq(26, 0); vector<vl>occ(26, vl());
        int ind = 1;
        for(auto it : s){
            freq[it-'a']++;
            occ[it-'a'].push_back(ind);
            ind++;
        }
        int jumps = 0, cost = endd - beg;
        vl ans;
        for(int i = beg; i <= endd; i++)
        {
            jumps += freq[i-1];
            for(auto it : occ[i-1])
            {
                ans.push_back(it);
            }
        }

        cout << cost << " " << jumps << "\n";

        if(flag)
        {
            for(int i = 0; i < ans.size(); i++)
            {
                ans[i] = s.size() + 1 - ans[i];
            }
            reverse(ans.begin(), ans.end());
        }

        for(auto it : ans)
        {
            cout << it << " ";
        }
        cout << "\n";


        
    }
}