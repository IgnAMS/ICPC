#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double db;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back

void solve(){
    int n, X;
    cin >> n >> X;
    vector<ll, ll> a(n);
    map<int, int> freq;
    rep(i, n){
        cin >> a[i];
        freq[a[i]]++;
    }
    sort(a.begin(), a.end());
    bool ok = true;
    for(int i = 1; i<n; ++i){ 
        if(a[i] + a[i-1] == X){
            if(a[i] == a[i-1]){
                if(freq[a[i]] > (n-1)/2){
                    ok = false;
                }else{
                    vector<int> v2(freq[a[i]], a[i]);
                    vector<int> v1;
                    vector<int> v3;
                    rep(j, n){
                        if(a[j] < a[i]){
                            v1.push_back(a[j]);
                        }
                        if(a[j] > a[i]){
                            v3.push_back(a[j]);
                        }
                    }
                    int cnt = 0;
                }
            }else {

            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}

