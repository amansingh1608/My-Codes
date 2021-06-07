#include<iostream>
#include<vector>
using namespace std;
vector<int> printspiral( vector<vector<int> > A) {
    
    vector <int> answer;
    int t=0;
    int b=A.size()-1;
    int l=0;
    int r=A[0].size()-1;
    int dir=0;
    while(t<=b && l<=r){
        if(dir==0){
            for(int i=l;i<=r;i++){
                answer.push_back(A[t][i]);
                
            }
            t++;
        
        }
        else if(dir==1){
            for(int i=t;i<=b;i++){
                answer.push_back(A[i][r]);
                
            }
            r--;
            
        }
        else if(dir==2){
            for(int i=r;i>=l;i--){
                 answer.push_back(A[b][i]);
               
            }
            b--;
            }
        else if(dir==3){
            for(int i=b;i>=t;i--){
                answer.push_back(A[i][l]);

            }
            
            l++;
            
            
            
        }
        
       dir=(dir+1)%4; 
        
    }
    
    
    return answer;
    
}








int main(){

vector<vector<int> > mat;


for(int i=0;i<4;i++){
    vector<int> tt;
    for(int j=0;j<4;j++){

        int temp;
        cin>>temp;
        tt.push_back(temp);
    }
    mat.push_back(tt);
}


vector<int > ans=printspiral(mat);


for(int i:ans){
    cout<<i<<" ";
}


}