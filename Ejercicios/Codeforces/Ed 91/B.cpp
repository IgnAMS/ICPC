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
        string ans="";
        int contR=0, contS=0, contP=0;
        for(int i=0;i<linea.length();i++){
            if(linea[i]=='R') contR++;
            if(linea[i]=='S') contS++;
            if(linea[i]=='P') contP++;
        }
        if(contR >= contS && contR >= contP){
            for(int i=0;i<linea.length();i++) cout<<'P';
        }
        else if(contS >= contR && contS >= contP){
            for(int i=0;i<linea.length();i++) cout<<'R';
        }
        else if(contP >= contS && contP >= contR){
            for(int i=0;i<linea.length();i++) cout<<'S';
        }
        cout<<endl;
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}