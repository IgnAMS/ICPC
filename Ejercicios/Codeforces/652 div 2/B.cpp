//string::erase
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
        int a;
        cin>>a;
        string linea;
        cin>>linea;
        int last=-1;
        for(int i=0;i<linea.length();i++){
            if(linea[i]=='0') last=i;
        }
        for(int i=0;i<linea.length();i++){
            while(i<linea.length()-1 && linea[i]=='1' && linea[i+1]=='0' && i+1<last){
                linea.erase(linea.begin()+i+1);
                last--;
            }
            while(i>0 && linea[i]=='0' && linea[i-1]=='1'){
                //cout<<"matare el 1"<<endl;
                //cout<<i<<endl;
                linea.erase(linea.begin()+i-1);
                i--;
                last--;
            }
        }
        cout<<linea<<endl;
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}