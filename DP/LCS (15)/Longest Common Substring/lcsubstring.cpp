#include<iostream>
#include<vector>
using namespace std;

int lcs(string x,string y,int m,int n){

    vector<vector<int> > t(m+1,vector<int>(n+1));
    int ans=0;

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){


            if(x[i-1]==y[j-1]){
                t[i][j] = 1+t[i-1][j-1];
                if(ans<t[i][j]){
                    ans=t[i][j];
                }
            }
            else{
                t[i][j]=0;
            }
        }
    }

    return ans;
    //return t[m][n];



    
}

int main(){

    string x,y;
    cin>>x;
    cin>>y;

    cout<<lcs(x,y,x.size(),y.size())<<endl;
}