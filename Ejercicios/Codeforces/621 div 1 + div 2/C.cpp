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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    map<string, ll> mapa;
    map<char, ll> car;
    for(char c = 'a'; c <= 'z'; c++) {
        string aux(1, c);
        mapa[aux] = 0;
        for(char c2 = 'a'; c2 <= 'z'; c2++) { 
            aux.push_back(c2); 
            mapa[aux] = 0;
            aux.pop_back(); 
        }
    }
    for(auto c: s) {
        for(auto x: car) if(x.ss != 0) {
            string aux(1, x.ff);
            aux.push_back(c);
            mapa[aux] += x.ss;
        }
        car[c]++;
    }
    ll ans = 0;
    for(auto u: car) ans = max(ans, u.ss);
    for(auto u: mapa) ans = max(ans, u.ss);
    cout<<ans<<'\n';
    


    return 0;
}