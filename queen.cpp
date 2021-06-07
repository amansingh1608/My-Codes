#include<iostream>
using namespace std;
//int counter=0;

bool issafe(int mat[20][20],int row,int col,int n){

int i,j;
for(int i=0;i<col;i++){
if(mat[row][i]==1){
    return false;
}


}


for(i=row,j=col;j>=0 && i<n;i++,j--){

if(mat[i][j]){
    return false;
}

}


for(i=row,j=col;i>=0 && j>=0;i--,j--){
    if(mat[i][j]){
        return false;
    }
}


return true; 

}

void printsol(int mat[20][20],int n){


    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void nqueen(int mat[20][20],int col,int n){

if(col>=n){   
            
            printsol(mat,n);
            //counter++;
            cout<<endl;
            return;
       
    }    


for(int i=0;i<n;i++){
    if(issafe(mat,i,col,n)){
        mat[i][col]=1;
        nqueen(mat,col+1,n);
        mat[i][col]=0;
        //return;
    }

    

}





}


int main(){
while(1){

int n;
cin>>n;
int mat[20][20]={0};

nqueen(mat,0,n);

//cout<<counter<<endl;

}    




}