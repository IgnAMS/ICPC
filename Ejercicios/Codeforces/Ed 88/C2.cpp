#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  double hot,cold,ideal;
  while(t--){
    cin>>hot>>cold>>ideal;
    int low=1;
    int top=10000000;
    int mid;
    int ans;
    while(low<=top){
      mid=(low+top)/2;
      double val=(hot*mid+cold*(mid-1.0))/(2.0*mid-1);
      //printf("val: %lf, mid: %d\n",val,mid);
      if(val<ideal){
        top=mid-1;

      }
      else{
        low=mid+1;
        ans=mid;
      }
    }
    //cout<<ans<<endl;
    double m1=(double(ans)*hot+(double(ans)-1)*cold)/(double(ans)*2-1);
    double m2=(double(ans+1)*hot+double(ans)*cold)/(double(ans+1)*2-1);
    double min1=abs(double(hot+cold)/2.0-ideal);

    if(abs(m1-ideal)>abs(m2-ideal)) ans++;
    double min2=min(abs(m1-ideal),abs(m2-ideal));

    //printf("min1: %lf, min2: %lf\n",min1,min2);
    if(min1<=min2 && ans!=1){
      cout<<2<<endl;
    }
    else{
      cout<<ans*2-1<<endl;
    }
  }

  return 0;
}
