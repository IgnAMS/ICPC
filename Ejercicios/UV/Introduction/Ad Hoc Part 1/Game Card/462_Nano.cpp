#include<bits/stdc++.h>
using namespace std;
typedef pair<char,int> ci;
typedef pair<int,char> ic;
int main(){
  vector<char> spade;
  vector<char> heart;
  vector<char> diamond;
  vector<char> club;

  string linea;
  int sum=0;
  int sum2=0;
  map<char,int> m;
  m.insert(ci('S',0));
  m.insert(ci('H',1));
  m.insert(ci('D',2));
  m.insert(ci('C',3));
  map<char,int> a;
  a.insert(ic(0,'S'));
  a.insert(ic(1,'H'));
  a.insert(ic(2,'D'));
  a.insert(ic(3,'C'));
  vector<bool> k(4,false);
  vector<bool> j(4,false);
  vector<bool> q(4,false);
  for(int i=0;i<13;i++){
    cin>>linea;
    if(linea[0]=='K'){
      sum+=3;
      sum2+=3;
      k[m[linea[1]]]=true;
    }
    else if(linea[0]=='A'){
      sum+=4;
      sum2+=4;
    }
    else if(linea[0]=='Q'){
      sum+=2;
      sum2+=2;
      q[m[linea[1]]]=true;
    }
    else if(linea[0]=='J'){
      sum++;
      sum2++;
      j[m[linea[1]]]=true;
    }
    switch(linea[1]){
      case 'S': spade.push_back(linea[0]);
      case 'H': heart.push_back(linea[0]);
      case 'D': diamond.push_back(linea[0]);
      case 'C': club.push_back(linea[0]);
    }
  }
  for(int i=0;i<4;i++){
    if(k[i])
  }





}
