#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n, k;
    cin >> n >> k;
 
    int A[n + 1][n + 1];
 
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            cin >> A[i][j];
    
    // dp[i] = Answer if we consider 1...i
    vector<int> dp[n + 1];
    dp[0] = {0};
 
    for (int i = 1; i <= n; i++){
        priority_queue<array<int, 3>> pq;
 
        // Don't create an interval
        pq.push({dp[i - 1][0], i - 1, 0});
 
        // Create interval j+2...i (transition from j)
        // for (int j = i - 2; j >= -1; j--){
        //     pq.push({(j < 0 ? 0 : dp[j][0]) + A[j + 2][i], j, 0});
        // }
        for(int j = i; j >= 1; j--) {
            pq.push({(j < 2? 0: dp[j - 2][0]) + A[j][i], j - 2, 0});
        }
 
        while (pq.size() and dp[i].size() < k){
            auto [val, j, num] = pq.top(); pq.pop();
            cout<<val<<' '<<j<<' '<<num<<'\n';
            dp[i].push_back(val);
            
            if (j < 0 or num + 1 >= dp[j].size())
                continue;
            
            // Don't create interval
            if (j == i - 1)
                pq.push({dp[i - 1][num + 1], i - 1, num + 1});
            
            // Create interval j+2...i (transition from j)
            else 
                pq.push({dp[j][num + 1] + A[j + 2][i], j, num + 1});
        }
        cout<<'\n';
    }
    for (int i : dp[n])
        cout << i << " ";
    cout << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int tc; 
    cin >> tc;
 
    while (tc--) 
        solve();
}