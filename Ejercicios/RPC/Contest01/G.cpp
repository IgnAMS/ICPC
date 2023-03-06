#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define repx(i,a,b) for(int i = a; i < b;i++)
#define rep(i, n) repx(i, 0, n)


int main() {
    ll y; cin>>y;
    if(y == 1) { 
        cout<<"0\n";
        return 0;
    }
    vector<ll> F(10); 
    F[0] = 1;
    repx(i, 1, 10) F[i] = F[i - 1] * i;
    string s = "";
    while(y) {;
        if(y == 1) s += '1', y = 0;
        else {
            auto it = lower_bound(F.begin(), F.end(), y);
            if(it != F.end()) {
                int ind;
                if(*it == y) ind =  lower_bound(F.begin(), F.end(), y) - F.begin();
                else ind = prev(lower_bound(F.begin(), F.end(), y)) - F.begin();
                s += char('0' + ind);
                // cout<<ind<<' '<<F[ind]<<'\n';
                y -= F[ind];
            }
            else {
                int ind = prev(lower_bound(F.begin(), F.end(), y)) - F.begin();
                s += char('0' + ind);
                // cout<<ind<<' '<<F[ind]<<'\n';
                y -= F[ind];
            }
            
        }
        
    }
    reverse(s.begin(), s.end());
    cout<<s<<'\n';
    
}

