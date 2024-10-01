#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define INF (int)1e9
#define pb push_back
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    OJ;
    int t; cin>>t;
    ll a,b,n,m;
    while(t--){
        cin>>a>>b>>n>>m;
        
        while(true){
            bool atleastone=false;
            cout<<"a: "<<a<<", b: "<<b<<", n: "<<n<<", m: "<<m<<endl;
            if(a>b && b>0 && m>0){ //hay mas galletas de vainilla que de chocolate
                ll rest=min({a-b,m,b});
                b-=rest;
                m-= rest;
                atleastone=true;
            }
            else if(a<=b && a>0 && m>0){//hay mas galletas de chocolate que de vainilla
                ll rest=min({a,m});
                a-=rest;
                a-=rest;
                atleastone=true;
                //cout<<"debi entrar aca "<<"min(n-a,)"<<endl;
            }
            if(a>b && a>0 && n>0){ //si igual cantidad de galletas el bro se come una
                //the guest selects the chocolate cookie
                ll rest=min({a,a-b,n});
                a-=rest;
                n-=rest;
            }
            else if(a<=b && b>0 && n>0){
                ll rest=min(b,n);
                b-=rest;
                n-=rest;
            }
            if(n==0 && m==0){
                cout<<"Yes"<<endl;
                break;
            }
            if(!atleastone){
                cout<<"No"<<endl;
                break;
            }
        }
       
    }
    


    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}