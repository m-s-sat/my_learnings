#include<iostream>
#include<vector>
using namespace std;

void mergeArray(vector<int> &arr,int l,int mid,int r){
    vector<int> temp;
    int index1 = l;
    int index2 = mid+1;
    while(index1<=mid&&index2<=r){
        if(arr[index1]>arr[index2]){
            temp.push_back(arr[index2++]);
        }
        else{
            temp.push_back(arr[index1++]);
        }
    }
    while(index1<=mid){
        temp.push_back(arr[index1++]);
    }
    while(index2<=r){
        temp.push_back(arr[index2++]);
    }
    for(int i=l;i<=r;i++){
        arr[i] = temp[i-l];
    }
}


void mergeSortArray(vector<int> &arr,int l,int r){
    if(l>=r){
        return ;
    }
    int mid = (l+r)/2;
    mergeSortArray(arr,l,mid);
    mergeSortArray(arr,mid+1,r);
    mergeArray(arr,l,mid,r);
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSortArray(arr,0,n-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}