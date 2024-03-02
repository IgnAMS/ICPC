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
    if(n == 1) {
        cout<<"ab\n";
        cout<<"ba\n";
        return 0;
    }

    string s1 = "", s2 = "";
    
    rep(i, 2 * n) {
        if(i < n) s1 += 'a';
        else s1 += 'b';
    }
    rep(i, n - 1) s2 += 'a';
    s2 += 'b';
    s2 += 'a';
    rep(i, n - 1) s2 += 'b';

    
    cout<<s1<<'\n';
    cout<<s2<<'\n';

    return 0;
}

// 2 -> "baba", "abab" f() = bba (3)
// 2 -> "aabb", "abba" f() = aab (3)
// 2 -> "aabb", "abab" f() = aab(3)
// 2 -> "aabb", "baab" f() = ba(2)
// 2 -> 
// 3 -> "bababa", "ababab" f() = bbba (4) 
// 4 -> "babababa", "abababab" f() = bbbaa(5)
// 
// 
// 
// 
// 