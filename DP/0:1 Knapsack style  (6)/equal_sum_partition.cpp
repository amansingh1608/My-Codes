#include<iostream>
#include<vector>
using namespace std;

bool subset(vector<int> nums,int n){
    int sumtotal=0;
    for(int i=0;i<n;i++){
        sumtotal+=nums[i];
    }
    if(sumtotal%2!=0){
        return false;
    }
    

    int sum=sumtotal/2;

    vector<vector<bool> > t(n+1,vector<bool> (sum+1,false));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum+1;j++){
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

    if(subset(nums,n)){
        cout<<"Possible"<<endl;
    }
    else{
        cout<<"Not possible"<<endl;
    }
    


}