#include<iostream>
#include<vector>
using namespace std;

vector<int> heap;


void swap(int i,int j){
    int temp=heap[i];
    heap[i]=heap[j];
    heap[j]=temp;

}

void insert(int data){
if(heap.size()==0){
heap.push_back(data);
}
else{
    heap.push_back(data);
    int index=heap.size()-1;
    while(index>0 && heap[index]<heap[(index-1)/2]){
        swap(index,(index-1)/2);
        index=(index-1)/2;
    }
}
}
void heapify(int i){
    if(i==heap.size()-1){
        return;
    }

    if(heap[i]<heap[(2*i)+1] && heap[i]<heap[(2*i)+2]){
        return;
    
    }
    int a=heap[(2*i)+1];
    int b=heap[(2*i)+2];
    a < b ? swap(i,(2*i)+1):swap(i,(2*i)+2);
   a < b ? heapify((2*i)+1) : heapify((2*i)+2);
    
}

int extractminimum(){
 int ans=heap[0];
swap(0,heap.size()-1);

heap.erase(heap.end());
heapify(0);
return ans;
}
void printheap(){

    for(int i=0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }

    cout<<endl<<endl;
}


int main(){
    int arr[10]={15,10,3,2,8,7};
    for(int i=0;i<6;i++){

        insert(arr[i]);
        printheap();
    }



   cout<< "The minimum extracted was "<< extractminimum()<<endl<<endl;
   printheap();







}