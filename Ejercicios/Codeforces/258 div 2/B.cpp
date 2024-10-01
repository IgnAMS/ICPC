#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
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
    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];
    vl SA(n); rep(i, n) SA[i] = A[i];
    sort(SA.begin(), SA.end());

    bool oc = 0;
    pll ans = {1, 1};
    int i = 0;
    while(i < n) {
        if(SA[i] != A[i] and !oc) {
            oc = 1;
            ans.ff = i + 1;
            int ind = lower_bound(SA.begin(), SA.end(), A[i]) - SA.begin();
            while(i < n and ind >= 0 and A[i] == SA[ind]) i++, ind--;
            ans.ss = i;
            continue;
        }
        else if(SA[i] != A[i] and oc) {
            cout<<"no\n";
            return 0;
        }
        else {
            i++;
        }
    }
    cout<<"yes\n";
    cout<<ans.ff<<' '<<ans.ss<<'\n';



    return 0;
}