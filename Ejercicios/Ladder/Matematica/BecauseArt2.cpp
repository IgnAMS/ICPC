#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,b) for(int i=0; i<b; i++)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
typedef vector<db> vd;
#define ff first
#define pb push_back
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


#define PI acos(-1.0L)

typedef complex<double> C;
void fft(vector<C> &a)
{
    int n = a.size(), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);
    for (static int k = 2; k < n; k *= 2)
    {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, PI / k);
        repx(i, k, 2 * k) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
    vi rev(n);
    rep(i, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2) for (int i = 0; i < n; i += 2 * k) rep(j, k)
    {
        auto x = (double *)&rt[j + k], y = (double *)&a[i + j + k];
        C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
        a[i + j + k] = a[i + j] - z, a[i + j] += z;
    }
}

vi conv(const vi &a, const vi &b)
{
    if (a.empty() || b.empty()) return {};
    vd res(a.size() + b.size() - 1);
    int L = 32 - __builtin_clz(res.size()), n = 1 << L;
    vector<C> in(n), out(n);
    copy(a.begin(), a.end(), in.begin());
    rep(i, b.size()) in[i].imag(b[i]);
    fft(in); for (auto &x : in) x *= x;
    rep(i, n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out); rep(i, res.size()) res[i] = imag(out[i]) / (4 * n);
    vi res2(res.size());
    rep(i, res.size()) res2[i] = round(res[i]);
    return res2;
}
const int mxN = 1e5+5;

ll Mx[mxN];
ll Mn[mxN];

void solve(vi& F, vi& C, bool mx) {
    vi FP, FN, CP, CN;
    int n = F.size();
    rep(i, n) {
        if(F[i] <= 0) FN.pb(F[i]);
        else FP.pb(F[i]);
        if(C[i] < 0) CN.pb(C[i]);
        else CP.pb(C[i]);
    }

    int fp = 0, fn = 0;
    int cp = 0, cn = 0;
    ll ans = 0;
    ll ind = 0;
    sort(FN.begin(), FN.end());
    sort(CN.begin(), CN.end());
    sort(CP.begin(), CP.end(), greater<ll>());
    sort(FP.begin(), FP.end(), greater<ll>());
    // cout<<"FN: "; for(auto u: FN) cout<<u<<' '; cout<<'\n';
    // cout<<"CN: "; for(auto u: CN) cout<<u<<' '; cout<<'\n';
    // cout<<"FP: "; for(auto u: FP) cout<<u<<' '; cout<<'\n';
    // cout<<"CP: "; for(auto u: CP) cout<<u<<' '; cout<<'\n'; cout<<'\n';
    while(fn < FN.size() and cn < CN.size() and fp < FP.size() and cp < CP.size()) {
        if(FN[fn] * CN[cn] >= FP[fp] * CP[cp]) ans += FN[fn++] * CN[cn++];
        else ans += FP[fp++] * CP[cp++];
        // cout<<ans<<'\n';
        if(mx) Mx[ind] = ans;
        else Mn[ind] = ans;
        ind++;
    }
    while(fn < FN.size() and cn < CN.size()) {
        ans += FN[fn++] * CN[cn++];
        // cout<<ans<<'\n';
        if(mx) Mx[ind] = ans;
        else Mn[ind] = ans;
        ind++;
    }
    while(fp < FP.size() and cp < CP.size()) {
        ans += FP[fp++] * CP[cp++];
        // cout<<ans<<'\n';
        if(mx) Mx[ind] = ans;
        else Mn[ind] = ans;
        ind++;
    }
    vi Neg, Pos;
    repx(i, fn, FN.size()) Neg.pb(FN[i]);
    repx(i, cn, CN.size()) Neg.pb(CN[i]);
    repx(i, fp, FP.size()) Pos.pb(FP[i]);
    repx(i, cp, CP.size()) Pos.pb(CP[i]);
    sort(Neg.begin(), Neg.end(), greater<ll>());
    sort(Pos.begin(), Pos.end());
    // cout<<"Neg: "; for(auto u: Neg) cout<<u<<' '; cout<<'\n';
    // cout<<"Pos: "; for(auto u: Pos) cout<<u<<' '; cout<<'\n'; cout<<'\n'; 
    vi X = conv(Neg, Pos);
    // cout<<"X: "; for(auto u: X) cout<<u<<' '; cout<<"\n\n";
    repx(i, ind, n) {
        // ans += X[i - ind];
        // cout<<ans<<'\n';
        if(mx) Mx[i] = ans + X[i - ind];
        else Mn[i] = ans + X[i - ind];
        // cout<<X[i]<<' '; cout<<'\n';
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vi F(n), C(n);
    rep(i, n) cin>>F[i];
    rep(i, n) cin>>C[i];
    solve(F, C, 1);
    rep(i, n) F[i] = -F[i];
    solve(F, C, 0);
    rep(i, n) cout<<-Mn[i]<<' '<<Mx[i]<<'\n';

    return 0;
}