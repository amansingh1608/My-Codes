#include<bits/stdc++.h>
using namespace std;
int solve(int e,int f,vector<vector<int> > & map){
    if(f==0 || f==1){
        return f;
    }
    if(e==1){
        return f;
    }
    if(map[e][f]!=-1){
        return map[e][f];
    }
    int mini=INT_MAX;
    for(int k=1;k<=f;k++){
        int temp=1+max(solve(e-1,k-1,map),solve(e,f-k,map));
        mini=min(temp,mini);
    }
    return map[e][f]=mini;
    
    
    
    
}
int main()
 {
    
    int t;
    cin>>t;
    
    while(t--){
        int e,f;
        cin>>e>>f;
        vector<vector<int> > map(e+1,vector<int> (f+1,-1));
        cout<<solve(e,f,map)<<endl;
    
    
    }
	
}