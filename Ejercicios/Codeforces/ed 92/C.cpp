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
        string linea;
        cin>>linea;
        int cont=0;
        int maxi=0;
        for(char a='0';a<='9';a++){
            for(char c= '0'; c<='9';c++){
                if(a==c) continue;
                cont=0;
                int low=-1;
                for(int i=0;i<linea.length();i++){
                    if(linea[i]==a){
                        low=i;
                    }
                    if(low!=-1 && linea[i]==c){
                        cont++;
                        low=-1;
                    }
                }
                maxi=max(maxi,cont*2);
            }
        }
        //cout<<maxi<<endl;
        for(char a='0';a<='9';a++){
            cont=0;
            for(int i=0;i<linea.length();i++){
                if(linea[i]==a) cont++;
            }
            maxi=max(cont,maxi);
        }
        cout<<linea.length()-maxi<<endl;
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}   