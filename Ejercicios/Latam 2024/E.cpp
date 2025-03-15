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
    vl X(n + 1, 0);
    ll A[n]; 
    rep(i, n) {
        cin>>A[i];
        X[A[i]] = 1;
    }


    ll l = 0, r = n - 1;
    ll prevl = 0, prevr = n - 1;
    while(l < n and A[l] == 0) l++;
    while(r >= 0 and A[r] == 0) r--;

    bool pos = 1;
    repx(i, 1, n + 1) {
        if(X[i]) continue;
        // se acabo si es que pasa eso 
        if(l > r) {
            rep(j, n) if(A[j] == 0) {
                A[j] = i;
                i++; 
            }
            break;
        }
        if(A[l] < A[r]) {
            repx(j, prevl, l) {
                if(X[i]) {
                    pos = 0;
                    break;
                }
                A[j] = i;
                i++;
            }
            l++;
            prevl = l;
            while(l < n and A[l] == 0) l++;
        }
        else {
            for(int j = prevr; j > r; j--) {
                if(X[i]) {
                    pos = 0;
                    break;
                }
                A[j] = i;
                i++;
            }
            r--;
            prevr = r;
            while(r >= 0 and A[r] == 0) r--;
        }
        if(!pos) break;
    }

    bool crec = 1;
    rep(i, n - 1) {
        if(crec == 1 and A[i] > A[i + 1]) {
            crec = 0;
        }
        if(crec == 0 and A[i] < A[i + 1]) {
            pos = 0;
        }
    }
    if(pos) {
        rep(i, n) cout<<A[i]<<' '; cout<<'\n';
    }
    else cout<<"*\n";




    return 0;
}