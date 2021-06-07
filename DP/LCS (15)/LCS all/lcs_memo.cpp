#include<iostream>
#include<vector>
using namespace std;

int lcs(string x,string y,int n,int m,vector<vector<int> > &t){

    if(n==0 || m==0){
        return 0;
    }

    if(t[n][m]!=-1){
        return t[n][m];
    }
    if(x[n-1]==y[m-1]){
        return t[n][m]=1+lcs(x,y,n-1,m-1,t);
    }
    else{
        return t[n][m]=max(lcs(x,y,n-1,m,t),lcs(x,y,n,m-1,t));
    }
}


int main(){
    string x,y;
    cin>>x>>y;

    int n=x.size();
    int m=y.size();
    vector<vector<int> > t(n+1,vector<int>(m+1,-1));

    cout<<lcs(x,y,x.size(),y.size(),t)<<endl;

}