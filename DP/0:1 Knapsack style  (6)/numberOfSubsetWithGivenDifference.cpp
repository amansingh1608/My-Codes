#include<iostream>
#include<vector>
using namespace std;

int subset(vector<int> nums,int n, int sum){

    vector<vector<int> > t(n+1,vector<int> (sum+1));

    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j]=0;
            }
            if(j==0){
                t[i][j]=1;
            }
        }
    }



    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(nums[i-1]<=j){

                t[i][j] =  t[i-1][j-nums[i-1]] + t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];

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

    int diff;
    cin>>diff;

    int d=(diff+sum)/2;

    cout<<subset(nums,n,d)<<endl;
}