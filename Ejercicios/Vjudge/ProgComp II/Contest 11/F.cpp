#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second
#define pb push_back

struct e{
    int id,x,t,f;
    e(int id, int x, int t): id(id), t(t), x(x) {}
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<e> E1,E2;
    vector<ii> A,B;
    //0 es abrir, 1 es cerrar
    rep(i,n){
        int ai,af,bi,bf;
        cin>>ai>>af>>bi>>bf;
        A.pb({ai,af}); B.pb({bi,bf});
        E1.pb({i,ai,0}); E1.pb({i,af,1}); E2.pb({i,bi,0}); E2.pb({i,bf,1});
    }

    sort(E1.begin(),E1.end(),[&](const e& a, const e& b){
        if(a.x==b.x){
            return a.t<b.t;
        }
        return a.x<b.x;
    });

    sort(E2.begin(),E2.end(),[&](const e& a, const e& b){
        if(a.x==b.x){
            return a.t<b.t;
        }
        return a.x<b.x;
    });

    multiset<int> i1,i2;
    multiset<int> e1,e2;
    vector<bool> v1(n,1);
    vector<bool> v2(n,1);
    bool flag=0;
    
    rep(i,2*n){
        ii& b=B[E1[i].id];
        if(E1[i].t==1){
            i1.erase(i1.find(b.ff));
            e1.erase(e1.find(b.ss));
        }

        else{
            if(!i1.empty() and !(*i1.rbegin()<=b.ss and b.ff<=*e1.begin())){
                flag=1;
                break;
            }
            i1.insert(b.ff); e1.insert(b.ss);
        }
    }
    if(flag){ cout<<"NO\n"; return 0; }
    
    rep(i,2*n){
        ii& a= A[E2[i].id];
        if(E2[i].t==1){
            i2.erase(i2.find(a.ff));
            e2.erase(e2.find(a.ss));
        } 
        else{
            if(!i2.empty() and !(*i2.rbegin()<=a.ss and a.ff<=*e2.begin())) {
                flag=1;
                break;
            }
            
            i2.insert(a.ff); e2.insert(a.ss);
        }
    }

    if(flag) cout<<"NO\n";
    else cout<<"YES\n";


    return 0;
}