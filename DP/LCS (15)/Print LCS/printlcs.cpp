#include<iostream>
#include<vector>
using namespace std;

string lcs(string x,string y,int n,int m){
    vector<vector<int> > t(n+1,vector<int> (m+1));
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

   int i=n;
   int j=m;
   string ans="";

   while(i>0 && j>0){
       if(x[i-1]==y[j-1]){
           ans+=x[i-1];
           i--;
           j--;

       }
       else{

           if(t[i][j-1]>t[i-1][j]){
               j--;
           }
           else{
               i--;
           }
       }

   }

reverse(ans.begin(),ans.end());
   return ans;





}


int main(){
    string x,y;
    cin>>x>>y;

    cout<<lcs(x,y,x.size(),y.size())<<endl;
   
  
}