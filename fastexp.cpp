#include<iostream>
using namespace std;


int power(int x,int p){

    if(p==0){
        return 1;
    }
int temp=power(x,p/2);
if(p%2==0){

    return temp*temp;
}
else{
    return x*temp*temp;
}


}

int main(){

    int n,p;
    cin>>n>>p;


    cout<<power(n,p);
}