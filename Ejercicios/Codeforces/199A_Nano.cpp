#include<bits/stdc++.h>
using namespace std;

bool visit[100];
vector<unsigned long long> num;


unsigned long long fib(int a){
  if(visit[a]){
    return num[a];
  }
  else{
    visit[a]=true;
    if(a==0) return 0;
    else if(a==1) return 1;
    else{
      num.push_back(fib(a-1)+fib(a-2));
      return num[a];
    }
  }
}


void init(){
  num.push_back(0);
  num.push_back(1);
  for(int i=0;i<60;i++) visit[i]=false;
  for(int i=0;i<60;i++) fib(i);
}



int main(){
  init();
  int n;
  cin>>n;
  int ind;
  bool state=false;
  for(int i=0;i<60;i++){
    //cout<<num[i]<<" ";
    if(n==fib(i)){
      ind=i;
      break;
    }
    if(i==num.size()-1 || num[i]>n){
      state=true;
      break;
    }
  }
  if(state) cout<<"I'm too stupid to solve this problem\n";
  else{
    cout<<0<<" "<<0<<" "<<n<<endl;
  }




  return 0;
}
