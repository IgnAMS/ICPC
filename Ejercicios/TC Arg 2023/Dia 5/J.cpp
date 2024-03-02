#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)

const int mxN = 105;

string equivalence(string s){
    if(s.size()%2 == 0){
        string s1 = equivalence(s.substr(0, (int)s.size()/2));
        string s2 = equivalence(s.substr((int)s.size()/2, (int)s.size()/2));
        return min(s1+s2, s2+s1);
    }
    return s;
}


int main() { 
    string s1, s2;
    cin >> s1 >> s2;
    if(equivalence(s1) == equivalence(s2)){
        cout << "YES";
    }else{
        cout << "NO";
    }
}