#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int oper=n*315+36962;
    //cout<<oper<<endl;
    oper/=10;
    int asd=abs(oper%10);
    cout<<asd<<endl;
  }


  return 0;
}
