#include<iostream>
#include<vector>
using namespace std;

int lcs1(string x,string y,string z,int n,int m,int k){
   
   int t[n+1][m+1][k+1];
   for(int i=0;i<=n;i++){
       for(int j=0;j<=m;j++){
           for(int p=0;p<=k;p++){
               if(i==0 || j==0 || p==0){
                   t[i][j][p]=0;
               }
           }
       }
   }
   
   for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
           for(int p=1;p<=k;p++){
               
               if(x[i-1]==y[j-1] && y[j-1]==z[p-1]){
                   t[i][j][p]=1+t[i-1][j-1][p-1];
               }
               else{
                    int tempmax=max(t[i-1][j][p],t[i][j-1][p]);
                t[i][j][p]=max(tempmax,t[i][j][p-1]);
                   
                 
               }
               
           }
       }
   }
   
   return t[n][m][k];
}
   
   
   
   
int main()
 {
    
    int t;
    cin>>t;
    
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        string x,y,z;
        cin>>x>>y>>z;
        
    
    cout<<lcs1(x,y,z,a,b,c)<<endl;
    
    
    }
	
}