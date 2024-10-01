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
    int t;
    cin>>t;
    while(t--){
        ll ans=0;
        ll pos=0;
        int menor=0;
        string linea; cin>>linea;
        int acc=0;
        vector<int> menores;
        for(int i=0;i<linea.length();i++){
            if(linea[i]=='+') acc++;
            else{
                acc--;
                if(acc<menor){
                    menores.push_back(i);
                    menor=acc;
                    pos=i;
                }
               
            }
        }
        for(int i=0;i<menores.size();i++){
            ans+=menores[i]+1;
        }
        ans+=linea.length();
        cout<<ans<<endl;
        

    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}