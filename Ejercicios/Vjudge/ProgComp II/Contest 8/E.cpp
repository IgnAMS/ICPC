#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef unsigned long long ull;
const int MAXLEN = 1e6;
ull mod=1e9+9;

struct RH_double{
    static const ull B = 26; // base
    static const ull P[2]; // primes
    static ull pow[2][MAXLEN];    
    static ull add(ull x, ull y, int a) { return (x + y) % P[a]; }
    static ull mul(ull x, ull y, int a) { return (x * y) % P[a]; }
    void init(int a){
        pow[a][0]=1;
        rep(i,MAXLEN) if(i) pow[a][i]=mul(B,pow[a][i-1],a);
    }
    void init(){ init(0); init(1);}
    vector<ull> h[2];
    int len;
    void init(vector<int>& s){
        init();
        len=s.size();
        rep(a,2){
            h[a].resize(len);
            h[a][0]=s[0];
            rep(i,len) if(i) h[a][i]=add(mul(h[a][i-1],B,a),s[i],a);
        }
    }
    RH_double(vector<int>& s){init(s);}
    RH_double(string&s){
        vector<int> tmp; for(char c: s) tmp.push_back(c-'a'+1);
        init(tmp);
    }
    ull hash(int a, int i, int j){
        if(i==0) return h[a][j];
        return add(h[a][j],P[a]-mul(h[a][i-1],pow[a][j-i+1],a),a);
    }
    ull hash(int i, int j){
        return hash(i,j,0)<<32 | hash(i,j,1);
    }

};
const ull RH_double::P[2] = {(ull)1e9+21, (ull)1e9+9};
ull RH_double::pow[2][MAXLEN];


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;
    vector<RH_double> rh1,rh2;
    string linea;
    rep(i,n){
        cin>>linea;
        RH_double aux(linea);
        rh1.emplace_back(aux);
    }
    rep(i,m){
        cin>>linea; 
        RH_double aux(linea); rh2.emplace_back(aux);
    }

    ull num=26*2000+1;
    ull pow[n];
    pow[0]=1;
    rep(i,n) if(i) pow[i]=(pow[i-1]*num)%mod;


    ull suma=0;
    rep(i,m) suma= (suma+(rh1[i].hash(0,m)*pow[i])%mod)%mod;
    ull mat1[n];
    mat1[m-1]=suma;
    for(int i=m;i<n;i++){
        suma= (suma - (rh1[i-m].hash(0,m)*pow[i-m])%mod)%mod;
        suma= (suma +(rh1[m].hash(0,m)*pow[i])%mod)%mod;
        mat1[i]=suma;
    }

    ull suma2=0;
    rep(i,m) suma2= (suma2+(rh2[i].hash(0,m)*pow[i])%mod)%mod;
    ull mat2[n];
    mat2[m-1]=suma2;
    for(int i=m;i<n;i++){
        rep(k,m) {
            suma2=(suma2-(rh2[k].hash(i-m,i-m)*pow[i-m])%mod)%mod;
            suma2=(suma2-(rh2[k].hash(i,i)*pow[i])%mod)%mod;
        }
        mat2[i]=suma2;
    }

    for(int i=m-1;i<n;i++){
        for(int j=m-1; j<n;j++){
            if(mat1[i]==mat2[j]){
                cout<<i<<" "<<j<<"\n";
                return 0;
            }
        }
    }

   


    return 0;
}