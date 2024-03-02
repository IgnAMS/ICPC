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
    ll A[n]; rep(i, n) cin>>A[i];
    ll ind_mayor = -1;
    bool pos = 1;
    rep(i, n - 1) {
        if(A[i] > A[i + 1] and ind_mayor != -1) pos = 0;
        else if(A[i] > A[i + 1]) ind_mayor = i;
    }
    if(ind_mayor == -1) {
        // A[i] <= A[i + 1] for all i
        cout<<"Phew\n";
        return 0;
    }
    // A[i] <= A[i + 1] for all i [0, ind_mayor - 1] and [ind_mayor, n - 1]
    if(A[0] < A[n - 1]) pos = 0;
    if(A[ind_mayor] < A[n - 1]) pos = 0;
    if(A[ind_mayor + 1] > A[0]) pos = 0;
    cout<<(pos? "Phew": "Lie")<<'\n';





    return 0;
}