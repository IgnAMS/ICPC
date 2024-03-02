#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second

const int mxN = 3e5+5;

ll n, x1, x2;
pair<ll, ll> a[mxN];

int main() {
    cin >> n >> x1 >> x2;
    rep(i, n){
        ll x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a, a+n);
    bool xd = false;
    swap(x1, x2);
    rep(_, 2){
        swap(x1, x2);
        set<ll> can;
        for(ll i = n-1; i>= 0; --i){
            if((x2+(n-i-1))/(n-i) <= a[i].first){
                can.insert(i);
            }
        }
        if(can.size() == 0) continue;
        rep(i, n){
            ll many = (x1+a[i].first-1)/(a[i].first);
            if(many+(n-*can.rbegin()) <= n-i){
                cout << "Yes\n";
                if(_ == 0){
                    cout << many << " " << n-(*can.rbegin()) << "\n";
                    for(int ff = i, cnt = 0; cnt < many and ff < n; ++cnt, ++ff){
                        cout << a[ff].second+1 << " ";
                    }      
                    cout << "\n";
                    for(ll ff = *can.rbegin(); ff<n; ++ff){
                        cout << a[ff].second+1 << " ";
                    }
                }else{
                    cout << n-(*can.rbegin()) << " " << many << "\n";      
                    for(ll ff = *can.rbegin(); ff<n; ++ff){
                        cout << a[ff].second+1 << " ";
                    } 
                    cout << "\n";
                    for(int ff = i, cnt = 0; cnt < many and ff < n; ++cnt, ++ff){
                        cout << a[ff].second+1 << " ";
                    }
                }
                xd = true;
                break;
            }
        }
        if(xd == true){
            break;
        }
        
    }
    if(xd == false){
        cout << "No\n";
    }
}