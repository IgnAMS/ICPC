#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef int ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    ll A[n]; 
    rep(i, n) cin>>A[i];
    rep(i, n) A[i]--;

    if(k <= 500) {
        map<vector<ll>, ll> mp;
        vl Acc(k, 0);
        mp[Acc] = -1;
        ll ans = 0;
        rep(i, n) {
            // cout<<"reviso para el acc "<<i<<'\n';
            Acc[A[i]]++;
            bool oc = 1;
            rep(j, k) if(Acc[j] == 0) oc = 0;
            if(oc) {
                rep(j, k) Acc[j]--;
            }
            if(mp.count(Acc)) {
                // cerr<<"encontre sol en "<<i<<'\n';
                ans = max(ans, (i - mp[Acc]) / k);
            }
            else mp[Acc] = i;
        }
        cout<<ans * k<<'\n';
    }

    else {
        ll ans = 0;
        vl Freq(k, 0);
        repx(largo, 1, n / k + 1) {
            // Quiero saber si todos los subsegmentos tienen largo 'largo'
            rep(i, k) Freq[i] = 0;
            ll curr = 0;
            for(int i = 0; i < largo * k; i++) {
                if(Freq[A[i]] == largo) curr--;
                Freq[A[i]]++;
                if(Freq[A[i]] == largo) curr++;
            }
            if(curr == k) {
                // cout<<"encontre sol en "<<0<<' '<<largo * k<<'\n';
                ans = max(ans, largo);
            }
            for(int l = 0, r = k * largo; r < n; l++, r++) {
                if(Freq[A[l]] == largo) curr--;
                Freq[A[l]]--;
                if(Freq[A[l]] == largo) curr++;

                if(Freq[A[r]] == largo) curr--;
                Freq[A[r]]++;
                if(Freq[A[r]] == largo) curr++;
                if(curr == k) {
                    // cout<<"encontre sol en "<<l + 1<<' '<<r<<'\n';
                    ans = max(ans, largo);
                }
            }
        }
        cout<<ans * k<<'\n';
    }






    return 0;
}