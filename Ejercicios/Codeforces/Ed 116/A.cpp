#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int ab = 0, ba = 0;
        rep(i, s.length() - 1){
            if(s[i] == 'a' and s[i+1] == 'b') ab++;
            if(s[i] == 'b' and s[i+1] == 'a') ba++; 
        }
        if(ab != ba){
            string s2 = s; s2[0] = 'a'; 
            int ab2 = 0, ba2= 0;
            rep(i, s.length() - 1){
                if(s2[i] == 'a' and s2[i+1] == 'b') ab2++;
                if(s2[i] == 'b' and s2[i+1] == 'a') ba2++; 
            }
            if(ab2 == ba2) { cout<<s2<<'\n'; continue; }
            s2 = s; s2[0] = 'b'; 
            ab2 = 0, ba2= 0;
            rep(i, s.length() - 1){
                if(s2[i] == 'a' and s2[i+1] == 'b') ab2++;
                if(s2[i] == 'b' and s2[i+1] == 'a') ba2++; 
            }
            if(ab2 == ba2) { cout<<s2<<'\n'; continue; }
            // primeros dos caso
            s2 = s; s2[s.length() - 1] = 'a'; 
            ab2 = 0, ba2= 0;
            rep(i, s.length() - 1){
                if(s2[i] == 'a' and s2[i+1] == 'b') ab2++;
                if(s2[i] == 'b' and s2[i+1] == 'a') ba2++; 
            }
            if(ab2 == ba2) { cout<<s2<<'\n'; continue; }
            s2 = s; s2[s.length() - 1] = 'b'; 
            ab2 = 0, ba2= 0;
            rep(i, s.length() - 1){
                if(s2[i] == 'a' and s2[i+1] == 'b') ab2++;
                if(s2[i] == 'b' and s2[i+1] == 'a') ba2++; 
            }
            if(ab2 == ba2) { cout<<s2<<'\n'; continue; }
        }
        else cout<<s<<'\n';
    }





    return 0;
}