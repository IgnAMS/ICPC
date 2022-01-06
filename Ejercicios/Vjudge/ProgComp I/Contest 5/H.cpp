#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;

bool range(int x, int a, int b) {
    return (a<=x && x<=b);
}

int R[6], C[6];
int G[3][2];

void connect(int i, int j, int x){
    R[i] ^= 1<<x; C[j] ^= 1<<x;
    G[i/2][j/3] ^= 1<<x; 
}

bool check(int i, int j, int x){
    return (R[i] & (1<<x)) || (C[j] & (1<<x)) || (G[i/2][j/3] & (1<<x)); 
}

struct A{
    int a=0, b=0; bool t=0;
    A() {}
    A(string s, int i, int j){
        if(s.size()==1) { 
            t=1; 
            if(range(s[0]-'0', 1, 9)) { a=s[0]-'0'; connect(i,j,a); }
        }
        else{
            if(range(s[0]-'0', 1, 9)) { a = s[0]-'0'; connect(i, j, a); }
            if(range(s[2]-'0', 1, 9)) { b = s[2]-'0'; connect(i, j, b); }
        }
    }
    void print(){
        if(t) cout<<a;
        else {
            cout<<(a? char(a+'0'):'-')<<'/'<<(b? char(b+'0'):'-');
        }
    }
};

A M[6][6];


bool backtrack(int i, int j, bool t){
    if(i==6) return 1;

    bool t_ = M[i][j].t? 0: !t;
    int j_ = t_? j: (j+1)%6;
    int i_ = j_<j? i+1: i;
    int& edit = t? M[i][j].b: M[i][j].a;   

    if(edit) return backtrack(i_, j_, t_);
    
    // M[i][j].print(); cout<<"\n";
    int inicio = 1, fin = 10;
    if(!t && M[i][j].b) fin= M[i][j].b;
    if(t) inicio = M[i][j].a + 1;
    repx(x, inicio, fin){
        if(!check(i, j, x)){
            connect(i, j, x);
            edit = x;
            // cout<<i<<" "<<j<<" "; M[i][j].print(); cout<<"\n";
            // cout<<i<<" "<<j<<" "<<t<<" "<<x+1<<"\n";
            if(backtrack(i_, j_, t_)) return 1;
            edit = 0;
            connect(i, j, x);
        }
    }
    return 0;
}


int main(){
    string linea;
    rep(i,6) rep(j,6) { cin>>linea; M[i][j] = A(linea, i, j); }
    backtrack(0,0,0);
    rep(i,6) { rep(j,6) { M[i][j].print(); cout<<' '; } 
                cout<<"\n"; }

    return 0;
}