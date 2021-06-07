#include<iostream>
using namespace std;
int arr[6][7]={ {1,0,0,1,0,1,0},{1,0,1,1,0,1,1},{0,0,0,1,1,0,1},{0,1,1,1,1,0,0},{1,1,1,1,0,0,0},{0,0,1,1,0,1,1}};
int solution [6][7]={0};

void printsolution(){

for(int i=0;i<6;i++){


	for(int j=0;j<7;j++){
		cout<<solution[i][j]<<" ";
	}
	cout<<endl;
}



}


void help(int x,int y){

	if(x<0 || y<0 || x>5|| y>6){

	return ;
}

if(arr[x][y]==0){
	return ;
}

// if(x=ax && y==ay){

// printsolution();
// }
if(arr[x][y]==1){
	arr[x][y]=1;
}





help(x+1,y);
help(x-1,y);
help(x,y+1);
help(x,y-1);



}


int main(){
help(3,4);


for(int i=0;i<6;i++){
	for(int j=0;j<7;j++){
		cout<<arr[i][j]<<" ";
	}
	cout<<endl;



}


}