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
        double a,b,c;
        cin>>a>>b>>c;
        //c siempre sera mas barato
        if(c<=a){
            if(c<a){
                cout<<-1<<" "<<1<<endl;
            }
            else{
                cout<<-1<<" "<<2<<endl;
            }
        }
        //a siempre sera mas barato
        else if(b*a<=c){
            if(b*a==c){
                if(b>0){
                    cout<<b-1<<" "<<-1<<endl;
                }
                else{
                    cout<<b+1<<" "<<endl;
                }
            }
            else{
                cout<<1<<" "<<-1<<endl;
            }
        }
        //a*b>c, es decir que el costo unitario de a es mayor al costo unitario de c
        else{
            cout<<1<<" "<<b<<endl;
        }
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}