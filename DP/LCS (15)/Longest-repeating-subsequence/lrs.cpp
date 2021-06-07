#include<iostream>
#include<vector>
using namespace std;


int lrs(string x){
    int n=x.size();
    vector<vector<int> > t(n+1,vector<int> (n+1));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){

                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==x[j-1] && i!=j){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }

        }
    }
    return t[n][n];

    
}

int main(){
    string s;
    cin>>s;
    cout<<lrs(s)<<endl;



}