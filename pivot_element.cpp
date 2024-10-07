#include<iostream>
using namespace std;

int pivot_element(int arr[],int size){
    int s=0,e=size-1;
    int mid  = s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    return arr[s];
}

int main(){
    int arr[100];
    int size;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int element = pivot_element(arr,size);
    cout<<"Pivot Element :- "<<element<<endl;
}