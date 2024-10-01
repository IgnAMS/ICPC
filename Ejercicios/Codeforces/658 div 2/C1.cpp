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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string linea1,linea2;
        cin>>linea1>>linea2;
        string aux=linea1;
        vector<int> ans;
        for(int i=n-1;i>=0;i++){
            if(aux[i]!=linea2[i]){
                if(aux[i]==linea2[0]){
                    ans.push_back(1);
                    ans.push_back(i);
                }
                else{
                    ans.push_back(i);
                }
                aux=aux.substr(0,i);
                for(int j=0;j<i;j++){
                    if(aux[j]=='0') aux[j]='1';
                    else aux[j]='0';
                }
                reverse(aux.begin(),aux.end());
            }
        }
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}