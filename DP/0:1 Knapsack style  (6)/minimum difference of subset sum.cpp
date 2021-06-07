#include<iostream>
#include<vector>
using namespace std;


int subset(vector<int> nums,int n,int sum){

    vector<vector<bool> > t(n+1,vector<bool>(sum+1,false));

    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j]=false;
            }
            if(j==0){
                t[i][j]=true;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){            

            if(nums[i-1]<=j){
                t[i][j]= t[i-1][j-nums[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    print(t);
    cout<<endl;

int mini=INT_MAX;

    for(int i=0;i<=sum/2;i++){
        if(t[n][i]==true){
             if(mini>sum-2*i){
                 mini=sum-(2*i);

             }
          
        }
    }
    return mini;
}


int main(){

    int n;
    cin>>n;
    int sum=0;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        sum+=temp;
        nums.push_back(temp);
    }


   cout<< subset(nums,n,sum)<<endl;
}