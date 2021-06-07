#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool solve(string a,string b){
    if(a==b){
        return true;
    }
    if(a.size()<=1){
        return false;
    }
    int n=a.size();

    for(int i=1;i<=n-1;i++){

        if(  (solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i)) )   || (solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i+1,n-i),b.substr(i+1,n-i)))){
            return true;
        }
    }

    return false;

}


int main(){

    string a,b;
    cin>>a>>b;
    if(a.size()!=b.size()){
        cout<<"False"<<endl;
        return 0;
    }
    if(solve(a,b)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    


}