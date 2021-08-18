#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, string> iii;
#define ff first.first
#define ss first.second
#define tt second

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int d, s; cin>>d>>s;
    deque<iii> q;
    string ans="-1";
    q.push_back(iii({0, 0}, ""));
    //repx(i, 1, 10) q.push_back(iii({i%d, i}, to_string(i)));
    vector<vector<bool>> V(505, vector<bool>(5005, false));
    V[0][0] = true;
    while(!q.empty()){
        iii aux = q.front(); q.pop_front();
        ll mod = aux.ff, sum = aux.ss;
        string num = aux.tt;
        if(mod == 0 and sum == s) { ans = num; break; }
        rep(i,10) if(sum + i <= s and !V[(mod*10 + i) % d][sum + i]){
            q.push_back({{(mod*10 + i) % d, (sum + i)}, num + to_string(i)});
            V[(mod*10 + i) % d][(sum + i)] = true;
        }
    }
    cout<<ans<<'\n';


    return 0;
}