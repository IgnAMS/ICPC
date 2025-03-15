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
    string s; cin>>s;
    int n = s.length();
    
    bool onlyR = 1, onlyU = 1, onlyL = 1;
    for(auto c: s) {
        if(c != 'R') onlyR = 0;
        if(c != 'R' and c != 'U') onlyU = 0;
        if(c != 'R' and c != 'L') onlyL = 0;
    }
    if(onlyR) {
        cout<<2<<' '<<1<<' '<<2<<'\n';
        cout<<2<<' '<<0<<'\n';
        cout<<0<<' '<<0<<'\n';
        return 0;
    }

    if(onlyU) {
        cout<<2<<' '<<1<<' '<<2<<'\n';
        cout<<"2 0\n";
        cout<<"0 0\n";
        return 0;
    }
    if(onlyL) {
        cout<<"2 2 1\n";
        cout<<"2 0\n";
        cout<<"0 0\n";
        return 0;
    }

    ll left = 0, right = 0, curr = 0;
    ll contL = 0, contU = 0;
    for(auto c: s) {
        contL += c == 'L';
        contU += c == 'U';
    }
    bool dir = 0;
    ll x = -1;
    rep(i, 2) {
        for(auto c: s) {
            if(c == 'R') continue;
            if(c == 'L') {
                curr--;
                if(curr < left and i) dir = 1, x = 0;
                left = min(left, curr);
            }
            if(c == 'U') {
                curr++;
                if(curr > right and i) dir = 0, x = 0; 
                right = max(right, curr);
            }
        }
    }
    
    if(x == -1) left--;
    if(!dir) {
        cout<<right - left + 1<<' '<<1<<' '<<right - left + 1<<'\n';
    }
    else {
        cout<<right - left + 1<<' '<<right - left + 1<<' '<<1<<'\n';
    }
    rep(i, right - left) {
        cout<<i + 2<<" 0\n";
    }
    cout<<"0 0\n";




    return 0;
}