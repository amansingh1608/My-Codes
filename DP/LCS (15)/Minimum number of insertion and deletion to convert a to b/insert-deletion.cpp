#include<iostream>
#include<vector>

using namespace std;

int lcs(string x,string y,int n,int m){
    vector<vector<int> > t(n+1,vector<int>(m+1));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            if(x[i-1]==y[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[n][m];




}


int main(){
    string x,y;
    cin>>x>>y;

    int lcslen=lcs(x,y,x.size(),y.size());

    int insertion=x.size()-lcslen;
    int deletion=y.size()-lcslen;

    cout<<insertion<<" "<<deletion<<endl;
}