#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
#define ff first
#define ss second



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<ll> H(n); rep(i, n) cin>>H[i];
    set<ii> vL, vR; // vL son los valles de la izquierda, vR son los de la derecha
    int maxi = 0, maxind;
    rep(i, n) {
        if(maxi < H[i]) vL.insert(ii(i, H[i])), maxi = H[i];
    }
    maxi = 0;
    for(int i = n-1; i >= 0; i--) {
        if(maxi < H[i]) 
            vR.insert(ii(-i, H[i])), maxi = H[i], maxind = i;
    }    

    // for(auto u : vL) cout<<-u.ff<<" "<<u.ss<<" - "; cout<<"\n";
    // for(auto u : vR) cout<<u.ff<<" "<<u.ss<<" - "; cout<<"\n";

    rep(_, m){
        string line; int i, h;
        cin>>line; cin>>i; i--;
        auto it_l = lower_bound(vL.begin(), vL.end(), ii(i, H[i]));
        auto it_r = lower_bound(vR.begin(), vR.end(), ii(-i, H[i]));
        if(line == "U"){
            cin>>h; H[i] = h; 
            if(h > maxi) maxind = i, maxi = h; 
            vector<ii> eL, eR;
            bool auxr = it_r->second < h;
            bool auxl = it_l->second < h;
            for(auto it = it_l; it != vL.end(); it++){
                if(it->second > h) break; 
                eL.emplace_back(it->first, it->second);
            }

            for(auto it = it_r; it != vR.end(); it++){
                if(it->second > h) break;
                eR.emplace_back(it->first, it->second);
            }
            
            for(auto u: eL) vL.erase(u);
            for(auto u: eR) vR.erase(u);
            if(eL.size() >= 1 or auxl) vL.insert(ii(-i, H[i]));
            if(eR.size() >= 1 or auxr) vR.insert(ii(i, H[i]));

            // for(auto u : vL) cout<<-u.ff<<" "<<u.ss<<" - "; cout<<"\n";
            // for(auto u : vR) cout<<u.ff<<" "<<u.ss<<" - "; cout<<"\n";

        }
        else if(line == "L"){
            if(i == maxind) cout<<i + 1<<"\n";
            else if(i < maxind) cout<<it_l->ff<<"\n";
            else cout<<-(-it_r->ff == i )next(it_r)->first + 1<<"\n";
        }
        else {
            if(i == maxind) cout<<i + 1<<"\n";
            else if(i < maxind) cout<<(it_l->first == i? it_l->first : next(it_l)->first) + 1<<"\n";
            else cout<<-it_r->first + 1<<"\n";
        }
    }

    return 0;
}