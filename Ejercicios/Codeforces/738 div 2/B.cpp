#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second



int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int i1=-1, i2;
        char c1 = s[0], c2;
        int index = 0;
        rep(i, n) if(s[i] != '?') { index = i; break; }
        bool aux = s[index] == 'R';
        for(int i = index - 1; i>=0; i--, aux = !aux){
            s[i] = aux? 'B':'R';
        }
        rep(i, n){
            if(s[i] == '?') continue;
            if(i1 == -1) i1 = i, c1 = s[i];
            else if(i - i1 <= 1){ // son consecutivos
                i1 = i, c1 = s[i];
            }
            else{
                // es 1 o 0 errores, se ajusta solo
                aux = c1 == 'R';
                repx(j, i1 + 1, i) s[j] = aux? 'B':'R', aux = !aux;
                i1 = i, c1 = s[i];
            }
        }
        aux = c1 == 'R';
        repx(j, i1 + 1, n) s[j] = aux? 'B' : 'R', aux = !aux;
        cout<<s<<'\n';

    }


    return 0;
}