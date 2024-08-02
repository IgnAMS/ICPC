#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double db;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define ff first
#define pb push_back

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll unos = 0, dos = 0;
    vl A(n); 
    multiset<ll> S;
    rep(i, n) {
        cin>>A[i];
        unos += (A[i] == 1);
        dos += (A[i] == 2);
        if(A[i] > 2) S.insert(A[i]);
    }
    sort(A.begin(), A.end());
    
    
    bool last = (S.size() == 0);
    
    // Saco los 1+2s
    for(int i = 0; i < min(unos, dos); i++) {
        if(i + 1 < min(unos, dos)) cout<<"(1+2)*";
        else if(dos == min(unos, dos) and unos == min(unos, dos) + 1 and S.size() == 0) cout<<"(1+1+2)\n", unos--;
        else if(dos == min(unos, dos) and unos == min(unos, dos) + 1) cout<<"(1+1+2)*", unos--;
        else if(max(unos, dos) > min(unos, dos)) cout<<"(1+2)*";
        else if(S.size() > 0) cout<<"(1+2)*";

        // no me quedan ni unos ni dos por lo que debo imprimir
        else cout<<"(1+2)\n";
    }
    // 
    ll mn = min(unos, dos);
    unos -= mn;
    dos -= mn;
    
    // Se acabaron los 1s por lo que imprimo los dos
    for(int i = 0; i < dos; i++) {
        if(i + 1 < dos) cout<<"2*";
        else if(S.size() > 0) cout<<"2*";
        else cout<<"2\n";
    }


    // No se acabaron los unos por lo que los sigo imprimiendo
    for(int i = 0; i < unos / 3; i++) {
        if(i + 1 < unos / 3) cout<<"(1+1+1)*";
        else if(S.size() == 0 and unos % 3 == 1) cout<<"(1+1+1+1)\n", unos--;
        else if(S.size() > 0 and unos % 3 == 1) cout<<"(1+1+1+1)*", unos--;
        else if(S.size() == 0 and unos % 3 == 0) cout<<"(1+1+1)\n";
        // S.size() > 0 o unos % 3 = 2
        else cout<<"(1+1+1)*";
    }

    // descuento los que tengo que descontar
    unos -= (unos / 3) * 3;
    // Me quedan 0 o 2 unos

    // No se acabaron los unos por lo que sigo imprimiendo
    for(int i = 0; i < unos / 2; i++) {
        if(i + 1 < unos / 2) cout<<"(1+1)*";
        else if(S.size() == 0) cout<<"(1+1)\n";
        else cout<<"(1+1)*";
    }
    unos -= (unos / 2) * 2;
    
    // Me queda un uno
    if(unos and S.size() > 0) {
        cout<<"(1+"<<*S.begin()<<")"<<"\n*"[S.size() > 1];
        unos--;
        S.erase(S.find(*S.begin()));
    }
    else if(unos) {
        cout<<"1\n";
    }
    
    for(auto it = S.begin(); it != S.end(); it++) {
        cout<<*it<<"\n*"[next(it) != S.end()];
    }
    


    return 0;
}