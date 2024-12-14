#include<iostream>
using namespace std;

int index_find(int *arr, int s,int e){
    int mid = s+(e-s)/2;
    if(s==e){
        return mid;
    }
    if(arr[mid]<arr[mid+1]){
        return index_find(arr,mid+1,e);
    }
    else{
        return index_find(arr,s,mid);
    }
}

int binary_search(int *arr,int s,int e,int k){
    if(s>e){
        return -1; 
    }
    int mid = s+(e-s)/2;
    if(arr[mid]==k){
        return mid;
    }
    else if(arr[mid]>k){
        return binary_search(arr,s,mid-1,k);
    }
    else{
        return binary_search(arr,mid+1,e,k);
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int index = index_find(arr,0,n-1);
    int left = binary_search(arr,0,index,k);
    int right = binary_search(arr,index+1,n-1,k);
    if(left==-1){
        cout<<"Present at "<<right<<endl;
    }
    else if(right==-1){
        cout<<"Present at "<<left<<endl;
    }
    else{
        cout<<"Not Present"<<endl;
    }
}