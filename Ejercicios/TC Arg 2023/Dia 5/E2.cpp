#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)

const int mxN = 105;
int memo[mxN][mxN][mxN];


string s1, s2, v;
int lps[mxN];

void init_lps() {
    int n = v.size();
    lps[0] = 0;
    for(int j = 1; j < n; j++)
    {
        int i = lps[j-1];
        while(v[i] != v[j] and i > 0) i = lps[i-1];
        lps[j] = v[i] == v[j] ? i+1 : 0;

        if(i > 0 && v[i] == v[lps[i-1]] && lps[i-1] != 0) lps[i-1] = lps[lps[i-1]-1];
    }
}




int dp(int i, int j, int z)
{
    if(s1.size() == i || s2.size() == j)
        return memo[i][j][z] = 0;

    if(memo[i][j][z] != -1)
        return memo[i][j][z];

    int ans = max(dp(i+1, j, z), dp(i, j+1, z));

    if(s1[i] == s2[j])
    {
        int nz = z;
        while(v[nz] != s1[i] && nz > 0) nz = lps[nz-1];
  
        if(v[nz] == s1[i])
        {
            if(nz+1 != v.size())
            {// no match
                ans = max(ans, 1 + dp(i+1, j+1, nz+1));
            }
        }
        else
            ans = max(ans, 1 + dp(i+1, j+1, nz));
    }   

    return memo[i][j][z] = ans;
}



string ss ="";
void dp2(int i, int j, int z)
{
   
    if(s1.size() == i || s2.size() == j)
        return;
    int ans = memo[i][j][z];
    //cout<<i<<" "<<j << " " << z << " "<<ans<< endl;

    if(dp(i+1, j, z) == ans)
        return dp2(i+1, j, z);
    if(dp(i, j+1, z) == ans)
        return dp2(i, j+1, z);

    if(s1[i] == s2[j])
    {
        int nz = z;
        while(v[nz] != s1[i] && nz > 0) nz = lps[nz-1];
  
        if(v[nz] == s1[i])
        {
            if(nz+1 != v.size())
            {// no match
                if(dp(i+1,j+1,nz+1) + 1 == ans)
                {
                    ss += s1[i];
                    return dp2(i+1,j+1,nz+1);
                }

            }
        }
        else
        {
            if(dp(i+1,j+1,nz) + 1 == ans)
            {
                ss += s1[i];
                return dp2(i+1,j+1,nz);
            }
        }

    }
    return;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2 >> v;
    
    memset(memo, -1, sizeof(memo));
    init_lps();
    if(dp(0, 0, 0) == 0)
        cout << "0\n";
    else {
        dp2(0, 0, 0);
        cout << ss << "\n";
    }
    
}