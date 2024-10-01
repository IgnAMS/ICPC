#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

ll Facts[200001];
ll invFacts[200001];

ll sols[200001];

inline ll mod(ll x, ll m) { return ((x %= m) < 0) ? x+m : x; }

void Extendedgcd(ll a, ll b, ll&g, ll& x, ll& y){
    ll r2, x2, y2, r1, x1, y1, r0, x0, y0, q;
    r2 = a, x2 = 1, y2 = 0;
    r1 = b, x1 = 0, y1 = 1;
    while (r1) {
        q = r2 / r1;
        r0 = r2 % r1;
        x0 = x2 - q * x1;
        y0 = y2 - q * y1;
        r2 = r1, x2 = x1, y2 = y1;
        r1 = r0, x1 = x0, y1 = y0;
    }
    g = r2, x = x2, y = y2;
}

ll invmod(ll a, ll m) { //MODULAR INVERSE
    ll g, x, y;
    Extendedgcd(a, m, g, x, y);
    if(g == 1){
        return mod(x, m);
    } // make sure 0 <= x < m
    return -1;
}

void solve(vi nums, ll prod, ll sum){
    for(ll x = nums.back(); x <= 200000; x++){
        ll unos = x*(prod-1) - sum;
        if(unos + 1 + nums.size() > 200000){
            break;
        }
        if(unos+1+nums.size() < 10){
            cout << unos+1+nums.size() << " ";
            for(int a = 0; a < unos; a++){
                cout << "1 ";
            }
            for(ll a : nums){
                cout << a << " ";
            }
            cout << x << endl;
            }
    }
    
}

void Help(vi nums, ll prod, ll sum){
    for(ll i = nums.back(); i*prod <= 200000; i++){
        nums.push_back(i);
        Help(nums, prod*i, sum+1);
        nums.pop_back();
    }

    solve(nums, prod, sum);
}


int main(){

    int n, p;
    cin >> n >> p;
    memset(sols, 0, sizeof(sols));

    Facts[0] = 1;
    invFacts[0] = 1;
    for(int a = 1; a <= n; a++){
        Facts[a] = (a*Facts[a-1])%p;
        invFacts[a] = invmod(Facts[a], p);
    }

    vi initial = {2};
    Help(initial, 2, 2);


    return 0;
}