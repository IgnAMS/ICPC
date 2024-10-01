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
    //OJ;
    int t; cin>>t;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        if(c==a && b==1){
            cout<<-1<<" "<<-1<<endl;
        }
        //c siempre sera mas barato y son iguales si b==1
        else if(c<=a){
            cout<<-1<<" "<<int(b)<<endl;
        }
        //a siempre sera mas barato excepto en b que son iguales
        //c>a
        else{
            if(c==a*b){ //ya que b!= 1
                cout<<1<<" "<<-1<<endl;
            }
            //c<a*b
            else if(c<a*b){
                cout<<1<<" "<<b<<endl;
            }
            //c>a*b
            else{
                cout<<1<<" "<<-1<<endl;
            }
        }
        
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}