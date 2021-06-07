#include<iostream>
#include<vector>
using namespace std;


int knapsack(vector<int> wt,vector<int> val,int w,int n){
    vector<vector<int> > t(n+1,vector<int> (w+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            
            if(i==0 || j==0){
                t[i][j]=0;
                continue;
            }
            
            if(wt[i-1]<=j){
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
            
        }
    }
    
    return t[n][w];
    
   
    
}

int main()
 {
    
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int w;
        cin>>w;
        vector<int> val;
        vector<int> wt;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            val.push_back(temp);
            
        }
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            wt.push_back(temp);
        }
        
        vector<vector<int> > t(n+1,vector<int>(w+1,-1));
        
        cout<<knapsack(wt,val,w,n)<<endl;
    
    
    }
	
}