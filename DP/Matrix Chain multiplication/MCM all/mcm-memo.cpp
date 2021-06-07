#include<iostream>
#include<vector>
using namespace std;
int mcm(vector<int> arr,int i,int j,vector<vector<int> > &t){
    
    if(i==j){
        return 0;
    }
    int mini=INT_MAX;
    for(int k=i;k<=j-1;k++){
        
        
        int cost= (t[i][k] == -1 ? mcm(arr,i,k,t) : t[i][k]) + (t[k+1][j]==-1 ? mcm(arr,k+1,j,t):t[k+1][j]) + arr[i-1]*arr[k]*arr[j];
        if(cost<mini){
            mini=cost;
        }
        
    }
    return t[i][j]=mini;
    
    
}
int main()
 {
    
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
            
        }
        vector<vector<int> > t(n+1,vector<int> (n+1,-1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==j){
                    t[i][j]=0;
                }
                
            }
        }
        
       cout<< mcm(arr,1,n-1,t)<<endl;
    
    
    }
	
}