#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
map<string,int> um;
bool isScramble(string a,string b ){
    if(a==b){
        return true;
    }
    if(a.size()<=1){
        return false;
    }
    int n=a.size();
    string key=a;
    key+=" ";
    key+=b;
    if(um.find(key)!=um.end() ){
        return um[key];
    }

    for(int i=1;i<=n-1;i++){

        if(  (isScramble(a.substr(0,i),b.substr(n-i,i)) && isScramble(a.substr(i,n-i),b.substr(0,n-i)) )   || (isScramble(a.substr(0,i),b.substr(0,i)) && isScramble(a.substr(i,n-i),b.substr(i,n-i)))){
            return um[key]=1;
        }
    }

    return um[key]=0;

}


int main(){

    string a,b;
    cin>>a>>b;
    if(a.size()!=b.size()){
        cout<<"False"<<endl;
        return 0;
    }

    if(isScramble(a,b)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    


}