    #include <bits/stdc++.h>
    using namespace std;
     
    const int N = 201;
    const int M = 201 * 60;
    int two[N], five[N], full[N];
    int n, k;
     
    int dp[N][M];
    int dp2[N][M];
     
    int main() {
        ios::sync_with_stdio(false);
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            while (x % 2 == 0) {
                two[i]++;
                x /= 2;
            }
            while (x % 5 == 0) {
                five[i]++;
                x /= 5;
            }
        }
     
        const int inf = 1e9;
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) dp[i][j] = dp2[i][j] = -inf;
     
        dp[0][0] = 0;
     
        for (int i = 0; i < n; i++) {
            for (int chosen = 0; chosen < k; chosen++) {
                for (int twos = 0; twos < M - two[i]; twos++) {
                    dp2[chosen][twos] = max(dp2[chosen][twos], dp[chosen][twos]);
                    dp2[chosen + 1][twos + two[i]] = max(dp[chosen][twos] + five[i], dp[chosen + 1][twos + two[i]]);
                }
            }
            memcpy(dp, dp2, sizeof dp2);
        }
     
        int answer = 0;
        for (int i = 0; i < M; i++) {
            answer = max(answer, min(i, dp[k][i]));
        }
     
        cout << answer << "\n";
     
        return 0;
    }