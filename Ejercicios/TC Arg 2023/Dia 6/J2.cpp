#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vl;
typedef pair<int, int> pll;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second



const int mxN = 300005;
int Mn[mxN][3];
int Ansautos[mxN][3];
// int Anscamiones[mxN][3];
ll inf = 1e7;

int solvemin(int i, int suma, int n, vl& A) {
    if(i == n and suma == 0) {
        Ansautos[i][suma] = 0;
        // Anscamiones[i][suma] = 0;
        return Mn[i][suma] = 0;
    }
    if(i == n and suma != 0) return inf;
    if(suma + A[i] > 3) return inf;
    if(Mn[i][suma] != -1) return Mn[i][suma];

    if(suma + A[i] == 1) {
        Mn[i][suma] = solvemin(i + 1, suma + A[i], n, A);
        Ansautos[i][suma] = Ansautos[i+1][suma+A[i]];
        // Anscamiones[i][suma] = Anscamiones[i+1][suma+A[i]];
    }
    if(suma + A[i] == 2) {
        Mn[i][suma] = min(solvemin(i + 1, 0, n, A) + 1, solvemin(i + 1, suma + A[i], n, A));
        if(solvemin(i + 1, 0, n, A) + 1 < solvemin(i + 1, suma + A[i], n, A)) {
            Ansautos[i][suma] = Ansautos[i+1][0] + 1;
            // Anscamiones[i][suma] = Anscamiones[i+1][0];
        }
        else {
            Ansautos[i][suma] = Ansautos[i+1][suma+A[i]];
            // Anscamiones[i][suma] = Anscamiones[i+1][suma+A[i]];
        }
    }
    if(suma + A[i] == 3) {
        Mn[i][suma] = solvemin(i + 1, 0, n, A) + 1;
        Ansautos[i][suma] = Ansautos[i+1][0];
        // Anscamiones[i][suma] = Anscamiones[i+1][0] + 1;
        // GO[i][suma] = {i + 1, 0};
    }
    return Mn[i][suma];
}

int solvemax(int i, int suma, int n, vl &A) {
    if(i == n and suma == 0) return 0;
    if(i == n and suma != 0) return -inf;
    if(suma + A[i] > 3) return -inf;
    if(Mn[i][suma] != inf) return Mn[i][suma];

    if(suma + A[i] == 1) Mn[i][suma] = solvemax(i + 1, suma + A[i], n, A);
    if(suma + A[i] == 2) {
        Mn[i][suma] = max(solvemax(i + 1, 0, n, A) + 1, solvemax(i + 1, suma + A[i], n, A));
    }
    if(suma + A[i] == 3) {
        Mn[i][suma] = solvemax(i + 1, 0, n, A) + 1;
    }
    return Mn[i][suma];
}



int main() {

    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];

    sort(A.begin(), A.end());
    vector<vl> seg;
    vl act;

    int i = 0;
    while(i < n) {
        if(i < n - 3 and A[i+1]-A[i] <= 1000 and A[i+2]-A[i+1] <= 1000 and A[i+3]-A[i+2] <= 1000) {
            cout<<"Impossible\n";
            return 0;
        }
        if(i < n - 2 and A[i+1]-A[i] >= 2000 and A[i+2]-A[i+1] >= 2000) {
            cout<<"Impossible\n";
            return 0;
        }

        if(i < n - 2 and A[i+2] - A[i+1] <= 1000 and A[i+1] - A[i] <= 1000) {
            act.push_back(3);
            if(i < n - 3 and A[i+3]-A[i+2] >= 2000) {
                seg.push_back(act);
                act.clear();
            }
            i += 3;
        }
        else if(i < n - 1 and A[i+1] - A[i] <= 1000) {
            act.push_back(2);
            if(i < n - 2 and A[i+2] - A[i+1] >= 2000) {
                seg.push_back(act);
                act.clear();
            }
            i += 2;
        }
        else {
            act.push_back(1);
            if(i < n - 1 and A[i+1] - A[i] >= 2000) {
                seg.push_back(act);
                act.clear();
            }
            i += 1; 
        }
    }
    if(act.size()) seg.push_back(act);
    act.clear();
    // for(auto vec: seg) {
    //     for(auto u: vec) cout<<u<<' '; cout<<'\n';
    // }

    bool ambiguo = 0;
    int autos = 0, camiones = 0;
    for(auto &vec: seg) {
        rep(i, vec.size() + 2) rep(j, 3) Mn[i][j] = inf;
        ll mx = solvemax(0, 0, vec.size(), vec);
        rep(i, vec.size() + 2) rep(j, 3) Mn[i][j] = -1;
        ll mn = solvemin(0, 0, vec.size(), vec);

        if(mn >= inf) {
            cout<<"Impossible\n";
            return 0;
        }
        // for(auto u: vec) cout<<u<<' '; cout<<'\n';
        if(mn != mx) ambiguo = 1;
        else {
            // i = 0; int suma = 0;
            // int cont = 0;
            // while(i != vec.size()) {
            //     if(suma + vec[i] == 1) i += 1, suma += vec[i];
            //     else if(suma + vec[i] == 2) {
            //         // Mn[i][suma] = min(solvemin(i + 1, 0, n, A) + 1, solvemin(i + 1, suma + A[i], n, A));
            //         if(Mn[i][suma] == Mn[i+1][0] + 1) {
            //             i += 1;
            //             suma = 0;
            //             autos += 1;
            //         }
            //         else i += 1, suma = 2;
            //     }
            //     else if(suma + vec[i] == 3) i += 1, suma = 0, camiones++;
            // }
            autos += Ansautos[0][0];
            camiones += mn - Ansautos[0][0];
        }
    }
    if(ambiguo) cout<<"Ambiguous\n";
    else {
        cout<<"Cars without trailers: "<<autos<<'\n';
        cout<<"Cars with trailers: "<<camiones<<'\n';
    }

    return 0;
}