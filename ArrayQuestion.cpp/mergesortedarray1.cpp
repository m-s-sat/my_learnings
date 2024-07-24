#include<iostream>
#include<vector>
using namespace std;

void sorted_array(int arr1[],int size1,int arr2[],int size2){
    int sorted[200];
    int i=0,j=0,k=0;
    while(i<size1&&j<size2){
        if(arr1[i]<arr2[j]){
            sorted[k++]=arr1[i++];
        }
        else{
            sorted[k++]=arr2[j++];
        }
    }
    while(i<size1){
        sorted[k++]=arr1[i++];
    }
    while(j<size2){
        sorted[k++]=arr2[j++];
    }
    for(int i=0;i<(size1+size2);i++){
        cout<<sorted[i];
    }
}

void take_input(int arr[],int size){
    cout<<"arr length :- ";
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
}

int main(){
    int arr1[100],arr2[100],sorted[200];
    int size1,size2;
    take_input(arr1,size1);
    take_input(arr2,size2);
    sorted_array(arr1,size1,arr2,size2);
}