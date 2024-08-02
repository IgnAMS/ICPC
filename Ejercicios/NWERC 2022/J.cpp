#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define rep(i, n) repx(i, 0, n)
#define ff first
#define ss second
typedef pair<ll, ll> pll;
typedef vector<ll> vl;


const double PI = acos(-1.0L);

const int mxN = 4e5+5, M = 1e9+7;


struct SEG{
    ll mx[4*mxN];
    multiset<ll> ss[4*mxN];
    void init(){
        memset(mx, -1, sizeof(mx));
    }
    void merge(int i){
        mx[i] = max(mx[2*i], mx[2*i+1]);
    }
    void upd(int l1, int r1, int l2, int r2, int i, ll val){
        if(l2 > r1 || r2 < l1)return;
        if(l1 <= l2 && r2<=r1){
            ss[i].insert(val);
            mx[i] = *ss[i].rbegin();
            return;
        }
        int m2 = (l2+r2)/2;
        upd(l1, r1, l2, m2, 2*i, val);
        upd(l1, r1, m2+1, r2, 2*i+1, val);
        merge(i);
    }
    void erase(int l1, int r1, int l2, int r2, int i, ll val){
        if(l2 > r1 || r2 < l1)return;
        if(l1 <= l2 && r2<=r1){
            ss[i].erase(ss[i].find(val));
            mx[i] = *ss[i].rbegin();
            return;
        }
        int m2 = (l2+r2)/2;
        upd(l1, r1, l2, m2, 2*i, val);
        upd(l1, r1, m2+1, r2, 2*i+1, val);
        merge(i);
    }
    ll qry(int l1, int r1, int l2, int r2, int i){
        if(l2 > r1 || r2 < l1) return -1;
        if(l1 <= l2 && r2 <= r1){
            return mx[i];
        }
        int m2 = (l2+r2)/2;
        return max(qry(l1, r1, l2, m2, 2*i), qry(l1, r1, m2+1, r2, 2*i+1));
    }
}seg;

int ans[mxN];

int main() {
    seg.init();
    int n;
    vector<vl> events;
    set<ll> s;
    int pos = 0;
    map<ll, ll> coords;
    cin >> n;
    rep(i, n){
        ll a, t;
        cin >> a >> t;
        events.push_back({a, 0, -(a + t), i});
        events.push_back({a + t, 1, -a, i});
        s.insert(a);
        s.insert(a + t);
    }
    for(auto val : s){
        coords[val] = pos++;
    }
    sort(events.begin(), events.end());
    for(auto& ev : events){
        if(ev[1] == 0){
            ll idili = seg.qry(coords[-ev[2]], pos, 0, pos, 1);
            seg.upd(coords[-ev[2]], coords[-ev[2]], 0, pos, 1, idili+1);
            ans[ev[3]] = idili + 1;
        }else{
            seg.erase(coords[-ev[2]], coords[-ev[2]], 0, pos, 1, ans[ev[3]]);

        }
    }
    rep(i, n){
        cout << ans[i] << " ";
    }
    return 0;
}