#include<iostream>
#include<vector>
using namespace std;

void multiply(vector<int> &res,int n){
    
    int carry=0;
    
    for(int i=0;i<res.size();i++){
        
        int prod=res[i]*n+carry;
        res[i]=prod%10;
        carry=prod/10;
    }
    
    while(carry){
        res.push_back(carry%10);
        carry=carry/10;
    }
    
    
    
    
    
}

void factorial(int n){
    
    vector<int> res;
    res.push_back(1);
    
    for(int i=2;i<=n;i++){
        multiply(res,i);
    }
    
    for(int i=0;i<res.size();i++){
        cout<<res[i];
    }
    cout<<endl;
    
    
}





int main()
 {
    
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        factorial(n);
        
    
    
    }
	
}