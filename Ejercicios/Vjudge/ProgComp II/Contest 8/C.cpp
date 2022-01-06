#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef unsigned long long ull;
const int MAXLEN = 1e6;

struct RH_double { // rolling hashing
    ull B = 131; // base
    static const ull P[2]; // primes
    static ull pow[2][MAXLEN];    
    ull add(ull x, ull y, int a) { return (x + y) % P[a]; }
    ull mul(ull x, ull y, int a) { return (x * y) % P[a]; }
    void init(int a) {
        pow[a][0] = 1;
        for(int i=1;i<MAXLEN;i++) pow[a][i] =  mul(B, pow[a][i-1], a);
    }
    void init() { init(0); init(1); }    
    vector<ull> h[2];
    int len;
    void init(vector<int>& s) {
        init();
        len = s.size();
        rep(a,2) {
            h[a].resize(len);
            h[a][0] = s[0];
            rep(i,len) if(i) h[a][i] = add(mul(h[a][i-1], B, a), s[i], a);
        }
    }
    RH_double(vector<int>& s) { init(s); }
    RH_double(string& s, char ref) { 
        vector<int> tmp; for (char c : s) tmp.push_back(c - ref + 1);
        init(tmp);
    }
    ull hash(int i, int j, int a) {
        if (i == 0) return h[a][j];
        return add(h[a][j], P[a] - mul(h[a][i-1], pow[a][j-i+1], a), a);
    }
    ull hash(int i, int j) {
        return hash(i,j,0) << 32 | hash(i,j,1);
    }
    ull hash() { return hash(0, len-1); }
};
// these lines are necessary for the code to compile
const ull RH_double::P[2] = {(ull)1e9+21, (ull)1e9+9};
ull RH_double::pow[2][MAXLEN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin>>s;
    RH_double rh(s,'0');
    int l1=0,r1=0;
    int l2=s.length()-1, r2=s.length()-1;
    int ans=0;
    while(l1<=l2){
        //cerr<<l1<<" "<<r1<<": "<<rh.hash(l1,r1)<<"\n";
        //cerr<<l2<<" "<<r2<<": "<<rh.hash(l2,r2)<<"\n\n";
        if(rh.hash(l1,r1) == rh.hash(l2,r2)){
            if(l1==l2) ans++; 
            else ans+=2;
            l1=++r1;
            r2=--l2;
        }
        else{
            r1++; l2--;
        }
    }
    cout<<ans<<"\n";

    return 0;
}