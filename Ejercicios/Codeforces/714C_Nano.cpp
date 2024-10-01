#include<bits/stdc++.h>
using namespace std;
int main(){
  long long a1,a2,b1,b2,k;
  long long ans=0;
  cin>>a1>>a2>>b1>>b2>>k;
  if(a2>=b2){
    if(a1<=b1){
      ans=b2-b1+1;
      if(b1<=k && k<=b2) ans--;
    }
    else if(a1>b2){
      ans=0;
    }
    else if(a1<=b2){
      ans=b2-a1+1;
      if(a1<=k && k<=b2) ans--;
    }
  }
  else if(b2>a2){
    if(b1<=a1){
      ans=a2-a1+1;
      if(a1<=k && k<= a2) ans--;
    }
    else if(b1>a2){
      ans=0;
    }
    else if(b1<=a2){
      ans=a2-b1+1;
      if(b1<=k && k<=a2) ans--;
    }
  }

  cout<<ans<<endl;



  return 0;
}
