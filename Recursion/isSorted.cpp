#include<iostream>
#include<vector>
using namespace std;

bool isSorted(int *arr,int n){
    if(n==0){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    return isSorted(arr+1,n-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(isSorted(arr,n)){
        cout<<"Sorted"<<endl;
    }
    else{
        cout<<"Not Sorted"<<endl;
    }
}