#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string line; cin>>line;
    int n = line.length();
    bool cambios[n-1];
    rep(i, n-1){
        if(line[i] != line[i+1]) cambios[i] = 1;
        else cambios[i] = 0;
    }
    vector<ll> imp; 
    rep(i, n-1) if(cambios[i]) imp.push_back(2*(i+1)+1);
    
    int sign = 1;
    if(imp.size() % 2 != (line[0] == 'A')) sign = -1;

    vector<ull> ans(20, 0);
    rep(i, (1LL<<int(imp.size()))){
        ull  x = 1;
        int cont = 0;
        rep(j, 20) if(i & (1LL<<j)) x *= imp[j], cont++;
        ans[cont] += x;
    }

    cout<<imp.size()<<'\n';
    rep(i, imp.size() + 1) {
        cout<<(sign == -1? "-":"")<<ans[i]<<" ";
        sign = sign * -1;
    }
    cout<<'\n';
    

    return 0;
}