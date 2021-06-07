#include<iostream>
#include<string>
using namespace std;

bool issafe(string s,int l,int i,int r){

if(l!=0 &&s[l-1]=='a' && s[i]=='b'){
  return false;
}
if(s[l]=='b'&& s[i]=='a'){
  return false;
}
return true;

}


void permute(string s,int l,int r){
  if(l==r){
    cout<<s<<" ";
  }

  else{

    for(int i=l;i<=r;i++){
      if(issafe(s,l,i,r)){

        swap(s[l],s[i]);
      permute(s,l+1,r);
      swap(s[l],s[i]);
      }
      
    }



  }
}




int main(){

  string s;
  cin>>s;
  permute(s,0,s.size()-1);
  
  }