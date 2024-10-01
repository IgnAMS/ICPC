#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k1,k2;
  deque<int> primer;
  deque<int> segundo;
  cin>>n;
  cin>>k1;
  int h;

  for(int i=0;i<k1;i++){
    cin>>h;
    primer.push_back(h);
  }

  cin>>k2;
  for(int i=0;i<k2;i++){
    cin>>h;
    segundo.push_back(h);
  }
  //cout<<segundo.front()<<endl;
  int cont=0;
  while(true){
    if(cont>200){
      cout<<-1<<endl;
      break;
    }
    //cout<<cont<<endl;
    //cout<<segundo.front()<<" "<<primer.front()<<endl;
    if(segundo.front() > primer.front()){

      cout<<"gano el segundo chaval con "<<segundo.front()<<" vs "<<primer.front()<<endl;
      segundo.push_back(primer.front());
      segundo.push_back(segundo.front());
      segundo.pop_front();
      primer.pop_front();
    }
    else if(segundo.front() < primer.front()){
      cout<<"gano el primero chaval con "<<primer.front()<<" vs "<<segundo.front()<<endl;
      primer.push_back(segundo.front());
      primer.push_back(primer.front());
      primer.pop_front();
      segundo.pop_front();
    }
    cont++;
    //cout<<cont<<endl;
    if(primer.empty()){
      cout<<cont<<" "<<2<<endl;
      break;
    }
    if(segundo.empty()){
      cout<<cont<<" "<<1<<endl;
      break;
    }
  }





  return 0;
}
