#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vi F(n), C(n);
    rep(i, n) cin>>F[i];
    rep(i, n) cin>>C[i];
    sort(F.begin(), F.end());
    sort(C.begin(), C.end());

    vi Fpos, Fneg, Cpos, Cneg;
    rep(i, n) {
        if(F[i] <= 0) Fneg.push_back(F[i]);
        else Fpos.push_back(F[i]);
        if(C[i] < 0) Cneg.push_back(C[i]);
        else Cpos.push_back(C[i]);
    }

    int ifp = 0, jfp = Fpos.size() - 1, ifn = 0, jfn = Fneg.size() - 1;
    int icp = 0, jcp = Cpos.size() - 1, icn = 0, jcn = Cneg.size() - 1;
    ll tmp = 0;
    rep(i, n) {
        // negatives
        if(ifn < Fneg.size() and jcp >= 0) {
            if(jfp >= 0 and icn < Cneg.size() and Fneg[ifn] * Cpos[jcp] < Fpos[jfp] * Cneg[icn]) tmp += Fneg[ifn++] * Cpos[jcp--];
            else if(jfp >= 0 and icn < Cneg.size()) tmp += Fpos[jfp--] * Cneg[icn++];
            else tmp += Fneg[ifn++] * Cpos[jcp--];
        }
        else if(jfp >= 0 and icn < Cneg.size()) {
            tmp += Fpos[jfp--] * Cneg[icn++];
        }
        // positives
        else {
            cerr<<"entre aca2\n";
            if(ifp <= jfp and icp <= jcp) {
                cerr<<Fpos[ifp++]<<' '<<Cpos[icp++]<<'\n';
                if(jfn >= ifn and jcn >= icn and Fpos[ifp] * Cpos[icp] < Fneg[jfn] * Cneg[jcn]) tmp += Fpos[ifp++] * Cpos[icp++]; 
                else if(jfn >= ifn and jcn >= icn) tmp += Fneg[jfn--] * Cneg[jcn--];
                else tmp += Fpos[ifp++] * Cpos[icp++];
            }
            else tmp += Fneg[jfn--] * Cneg[jcn--];
        }
        cout<<tmp<<'\n';
    }




    return 0;
}