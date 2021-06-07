#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<bool> > mat){
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool subset(vector<int> nums,int sum,int n){
    vector<vector<bool> > t(n+1,vector<bool> (sum+1,false));

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

                t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
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
    vector<int> nums;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);

    }
    int sum;
    cin>>sum;

    if(subset(nums,sum,n)){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not present"<<endl;
    }
}