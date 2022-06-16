#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt



vi A;
ll dfs(ll l, ll r, ll s) {
    int i = l, j;
    ll minh = *min_element(A.begin() + l, A.begin() + r + 1);
    ll best = 0;
    while(i < r) {
        while(i < r and A[i] == minh) i++; // primera posicion que no es minh
        j = i;
        while(j < r and A[j] != minh) j++;
        if(j == r and A[j] != minh) best += dfs(i, j, minh);
        else if(i == j and A[j] == minh) continue;
        else best += dfs(i, j - 1, minh);
        i = j;
    }
    return min(minh - s + best, r - l + 1);
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    A.assign(n, 0); rep(i, n) cin>>A[i];
    cout<<dfs(0, n - 1, 0)<<'\n';



    return 0;
}