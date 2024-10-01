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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        string line1, line2; cin>>line1>>line2;
        map<char, int> mp;
        if(!mp.count(line1[0])) mp[line1[0]] = 0;
        if(!mp.count(line2[0])) mp[line2[0]] = 0;
        if(!mp.count(line1[1])) mp[line1[1]] = 0;
        if(!mp.count(line2[1])) mp[line2[1]] = 0;
        mp[line1[0]]++, mp[line2[0]]++, mp[line1[1]]++, mp[line2[1]]++;
        if(mp.size() == 4) cout<<"3\n";
        if(mp.size() == 3) cout<<"2\n";
        if(mp.size() == 2) cout<<"1\n";
        if(mp.size() == 1) cout<<"0\n";  
    }



    return 0;
}