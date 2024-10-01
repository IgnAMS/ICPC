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
    while(t--){
        int n;
        cin>>n;
        if(n<=30){
            cout<<"NO"<<endl;
            continue;
        }
        //fake, cuando un numero es 6 evaluar diferencia, cuando es 10 y 14 igual
        cout<<"YES"<<endl;
        if(n==36){
            cout<<5<<" "<<6<<" "<<10<<" "<<15<<endl;
            continue;
        }
        if(n==40){
            cout<<9<<" "<<6<<" "<<10<<" "<<15<<endl;
            continue;
        }
        if(n==44){
            cout<<6<<" "<<7<<" "<<10<<" "<<21<<endl;
            continue;
        }
        cout<<6<<" "<<10<<" "<<14<<" "<<n-30<<endl;
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}