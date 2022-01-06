#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int match(string &p, string &t)
{
    int n = p.size(), m = t.size(), L[n]; L[0] = 0;
    rep(j, n - 1)
    {
        int i = L[j]; while (p[i] != p[j + 1] && i) i = L[i - 1];
        L[j + 1] = (p[i] == p[j + 1] ? i + 1 : 0);
    }
    int ans = 0, i = 0; rep(j, m)
    {
        while (p[i] != t[j] && i) i = L[i - 1];
        if (p[i] == t[j] && ++i == n) i = L[n - 1], ans++;
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s; 
    while(cin>>s and s != "."){
        int n = s.length(), L[n]; L[0] = 0;
        rep(j, n - 1){
            int i = L[j]; while (s[i] != s[j + 1] && i) i = L[i - 1];
            L[j + 1] = (s[i] == s[j + 1] ? i + 1 : 0);
        }

        rep(i, n) cout<<L[i]<<' '; cout<<'\n';
        int j = 0, prev = -1;
        while(j < n - 1){
            // cout<<"j: "<<j<<'\n';
            prev = j;
            while(j < n - 1 and L[j] == L[j+1] - 1) j++;
            j++;
        }
        // cout<<prev<<'\n';
        // cout<<L[n-1]<<' '<<n-prev-1<<'\n'; 
        if(L[n-1] != n - prev - 1) cout<<1<<'\n';
        else cout<<n / (prev + 1)<<'\n';
        // cout<<"termine\n\n";
    }

    return 0;
}