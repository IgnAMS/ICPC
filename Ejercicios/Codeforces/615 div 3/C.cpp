#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    vector<int> factors;
    int n;
    set<int> nums;
    cin>>n;
    while(n%2==0){
      factors.push_back(2);
      nums.insert(2);
      n/=2;
    }
    int aux=n;
    for(int i=3;i<=sqrt(aux);i+=2){
      while(n%i==0){
        nums.insert(i);
        factors.push_back(i);
        n/=i;
      }
    }
    if(n>2){
      factors.push_back(n);
      nums.insert(n);
    }
    //cout<<factors.size()<<" "<<nums.size()<<endl;
    if(factors.size()<3) cout<<"NO\n";
    else{
      int mult1,mult2=1,mult3;
      int top=factors.size();

      if(nums.size()>=3){
        cout<<"YES\n";
        mult1=factors[0];
        for(int i=1;i<top-1;i++){
          mult2*=factors[i];
        }
        mult3=factors[top-1];
        cout<<mult1<<" "<<mult2<<" "<<mult3<<endl;

      }
      else if(factors.size()==3 && nums.size()==3){
        cout<<"YES\n";
        mult1=factors[0];
        for(int i=1;i<top-1;i++){
          mult2*=factors[i];
        }
        mult3=factors[top-1];
        cout<<mult1<<" "<<mult2<<" "<<mult3<<endl;
      }
      else if(factors.size()>=4 && nums.size()>=2){
        cout<<"YES\n";
        mult1=factors[0];
        for(int i=1;i<top-1;i++){
          mult2*=factors[i];
        }
        mult3=factors[top-1];

        cout<<mult1<<" "<<mult2<<" "<<mult3<<endl;
      }
      else if(factors.size()>=6 && nums.size()==1){
        cout<<"YES\n";
        mult1=factors[0];
        mult3=factors[1]*factors[2];
        for(int i=3;i<top;i++){
          mult2*=factors[i];
        }
        cout<<mult1<<" "<<mult2<<" "<<mult3<<endl;
      }
      else{
        cout<<"NO\n";
      }

    }



  }


  return 0;
}
