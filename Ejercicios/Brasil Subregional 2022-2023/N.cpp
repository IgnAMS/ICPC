#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define rep(i, n) for(int i = 0; i<(int)n; ++i)

int main(){
    
    ll n, k, l;
    cin >> n;
    vector<ll> A(n), B(n);
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> B[i];
    cin >> k >> l;

    ll sum = 0, sum2 = 0;
    vector<ll> aux;

    rep(i, k) {
        sum += A[i];
        aux.push_back(B[i]);
    }
    sort(aux.begin(), aux.end());
    multiset<ll> upper, lower;
    rep(i, l){
        sum2 += aux.back();
        upper.insert(aux.back());
        aux.pop_back();
    }
    rep(i, k-l){
        lower.insert(aux.back());
        aux.pop_back();
    }
    ll ans = sum + sum2;
    //cout << ans << endl;
    for(int i = n-1; i >= n-k; i--){
        ll i2 = k - (n - i);
        sum += A[i] - A[i2];

        if(B[i] > *upper.begin()){
            sum2 += B[i] - *upper.begin();
            lower.insert(*upper.begin());
            upper.erase(upper.begin());
            upper.insert(B[i]);
        }
        else{
            lower.insert(B[i]);
        }

        if(lower.find(B[i2]) != lower.end()){
            lower.erase(lower.find(B[i2]));
        }
        else{
            upper.erase(upper.find(B[i2]));
            sum2 += -B[i2] + *prev(lower.end());
            upper.insert(*prev(lower.end()));
            lower.erase(prev(lower.end()));
        }        
        ans = max(ans, sum + sum2);
        
    }

    cout << ans << "\n";
}