#include<iostream>
using namespace std;

void sort012(int *arr,int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i;j++){
            if(*(arr+j)>*(arr+j+1)){
                swap(*(arr+j),*(arr+j+1));
            }
        }
    }
}

void printArray(int *ptr,int size){
    for(int i=0;i<size;i++){
        cout<<*(ptr+i)<<" ";
    }
}

int main(){
    int ptr[100];
    int *arr = ptr;
    int size;
    cin>>size;
    cout<<"Only 0,1,2 : - ";
    for(int i=0;i<size;i++){
        cin>>*(ptr+i);
    }
    sort012(ptr,size);
    printArray(ptr,size);
}