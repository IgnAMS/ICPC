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

int match(vi &p, vi &t){
    int n = p.size(), m = t.size(), L[n]; L[0] = 0;
    rep(j, n - 1){
        int i = L[j]; 
        while (p[i] != p[j + 1] && i) i = L[i - 1];
        L[j + 1] = (p[i] == p[j + 1] ? i + 1 : 0);
    }


    int ans = 0, i = 0; 
    rep(j, m) {
        bool ine;
        if(t[j] > i and p[i] > 1) ine = 1;
        else if(t[j] > i and p[i] == 0) ine = 0;
        else ine = (t[j] != p[i]); 
        cerr<<"p["<<i<<"]: "<<p[i]<<'\t'<<"t["<<j<<"]: "<<t[j]<<'\n';
        while(ine and i > 0){
            i = L[i - 1];
            if(t[j] > i) ine = 1;
            else ine = (t[j] == p[i]);  
        }
        cerr<<ine<<'\n';
        if(!ine){
            if(++i == n) { 
                i = L[n - 1]; 
                ans++;
            }
        }
    }
    return ans;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string target; cin>>target;
    int n; cin>>n;
    vi pattern(n); rep(i, n) cin>>pattern[i];
    
    vi t(target.length());
    map<char, int> m1;
    rep(i, target.length()){
        if(!m1.count(target[i])) t[i] = 0;
        else t[i] = i - m1[target[i]];
        m1[target[i]] = i;
    }
    map<int, int> m2; 
    vi p(pattern.size());
    rep(i, pattern.size()){
        if(!m2.count(pattern[i])) p[i] = 0;
        else p[i] = i - m2[pattern[i]];
        m2[pattern[i]] = i;
    }

    cout<<match(p, t)<<'\n';


    return 0;
}