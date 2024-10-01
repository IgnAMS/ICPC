#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int cont=0;
    cont+=n/100;
    n%=100;

    cont+=n/20;
    n%=20;

    cont+=n/10;
    n%=10;

    cont+=n/5;
    n%=5;
    cont+=n;
    cout<<cont<<endl; 

    return 0;
}