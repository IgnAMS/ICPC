#include<bits/stdc++.h>
using namespace std;

int main(){
  deque<int> deck1;
  deque<int> deck2;
  int n,k;
  cin>>n>>k;
  int h;
  for(int i=0;i<k;i++){
    cin>>h;
    deck1.push_back(h);
  }
  cin>>k;
  for(int j=0;j<k;j++){
    cin>>h;
    deck2.push_back(h);
  }

  int cont=0;
  while(cont<400 && !deck1.empty() && !deck2.empty()){
    cont++;
    if(deck1.front()>deck2.front()){
      deck1.push_back(deck2.front());
      deck1.push_back(deck1.front());
    }
    else{
      deck2.push_back(deck1.front());
      deck2.push_back(deck2.front());
    }
    deck1.pop_front();
    deck2.pop_front();

  }
  //cout<<cont<<endl;
  //cout<<deck1.empty()<<" "<<deck2.empty()<<endl;
  if(cont==400) cout<<-1<<endl;
  else if(deck1.empty()) cout<<cont<<" "<<2<<endl;
  else cout<<cont<<" "<<1<<endl;

  return 0;
}
