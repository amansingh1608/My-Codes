#include<bits/stdc++.h>
using namespace std;
int mcm(vector<int> arr,int i,int j,vector<vector<int> > &t){
    
    if(i==j){
        return 0;
    }
    int mini=INT_MAX;
    for(int k=i;k<=j-1;k++){
        
        
        int cost=  mcm(arr,i,k,t)  + mcm(arr,k+1,j,t) + arr[i-1]*arr[k]*arr[j];
        if(cost<mini){
            mini=cost;
        }
        
    }
    return mini;
    
    
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
      
       
        
       cout<< mcm(arr,1,n-1)<<endl;
    
    
    }
	
}