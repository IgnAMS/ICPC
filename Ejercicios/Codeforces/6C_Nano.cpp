#include<bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin>>a;
  int Array[a];
  double max=0;
  for(int i=0;i<a;i++){
    cin>>Array[i];
    max+=Array[i];
  }
  int asd=max;
  max/=2;
  //cout<<max<<endl;
  int ans=0;
  int sum=0;
  for(int i=0;i<=max;i++){
    if(sum>max){
      break;
    }
    else{
      if(sum<= asd-sum-Array[i]){
        ans++;
      }
      else{
        break;
      }
    }
    sum+=Array[i];
  }
  cout<<ans<<" "<<a-ans<<endl;






  return 0;
}
