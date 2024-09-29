#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)

const int mxN = 105;
int dp[mxN][mxN*mxN], id[mxN][mxN*mxN];


void solve(){
    memset(dp, -1, sizeof(dp)); 
    int n;
    cin >> n; 
    vector<int> a(n);
    int sum = 0;
    rep(i, n){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % 2 == 1){
        cout << -1;
        return;
    }
    dp[0][a[0]] == 0;
    for(int i = 1; i<n; ++i){
        for(int x = 0; x<sum; ++x){
            dp[i][x] = dp[i-1][x];
            id[i][x] = id[i-1][x];
        }
        for(int x = 0; x<sum; ++x){
            if(x-a[i] >= 0 && dp[i][x] == -1 && dp[i][x-a[i]] != -1){
                dp[i][x] = id[i][x-a[i]];
                id[i][x] = i;
            }
        }
    }
    bool ok = false;
    vector<int> v1;
    int obj = sum/2;
    for(int i = 0; i<n; ++i){
        if(dp[i][obj] != -1){
            ok = true;
            int idd = i;
            v1.push_back(idd);
            while(idd != -1 && idd != 0){
                idd = id[i][obj-a[i]];
                v1.push_back(idd);
            }
            break;
        }
    }
    sort(v1.begin(), v1.end());
    vector<int> used(n, 0);
    rep(i, v1.size()){
        used[v1[i]] = 1;
    }
    vector<int> v2;
    rep(i, n){
        if(!used[i]){
            v2.push_back(i);
        }
    }

    int sa = 0, sb = 0;
    vector<int> anss;
    while(v1.size() && v2.size()){
        if(sa <= sb){
            sa += v1.back();
            anss.push_back(v1.back());
            v1.pop_back();
        }else{
            sb += v2.back();
            anss.push_back(v2.back());
            v2.pop_back();
        }
    }
    while(v1.size()){
        sa += v1.back();
        anss.push_back(v1.back());
        v1.pop_back();
    }
    while(v2.size()){
        sb += v2.back();
        anss.push_back(v2.back());
        v2.pop_back();
    }
    for(int val : anss){
        cout << val << " ";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    solve();

    return 0;
}