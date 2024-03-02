#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second

ll M = 1e9+7;

int main() {
    
    ll ans = 1;
    priority_queue<ll, vl, greater<ll> > Down;
    priority_queue<ll> Up; multiset<ll> ambiguo;

    ll n, p;
    string s;
    bool o = 1;
    cin >> n;
    while(n--) {
        cin >> s >> p;
        if(s == "ADD")
        {
            if(!Up.empty() && Up.top() < p)
                Up.push(p);
            else if(!Down.empty() && Down.top() > p)
                Down.push(p);
            else{
                ambiguo.insert(p);
            }
        }
        else{
            cout << ambiguo.size() << endl;
            if(ambiguo.count(p))
            {
                ans *= 2;
                ans %= M;
                ambiguo.erase(ambiguo.find(p));
                for(auto it : ambiguo)
                {
                    cout << it << "=\n";
                    if(it < p)Down.push(it);
                    else Up.push(it);
                }
                ambiguo.clear();
            }
            else if(Up.top() == p)
            {
                cout <<"hola"<<endl;
                Up.pop();
            }
            else if(Down.top() == p)
            {
                cout <<"hola2"<<endl;
                Down.pop();
            }
            else{
                o = 0;
                break;
            }
            
        }

    }
    if(o)
        cout << ans << "\n";
    else
        cout << "0\n";
}