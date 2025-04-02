#include<iostream>
#include<vector>
using namespace std;

int count = 0;

void mergeThem(vector<int>&arr,int low,int mid,int high){
    vector<int>temp;
    int index1=low;
    int index2=mid+1;
    while(index1<=mid && index2<=high){
        if(arr[index1]>arr[index2]){
            temp.push_back(arr[index2++]);
            count+=(mid-index1+1);
        }
        else{
            temp.push_back(arr[index1++]);
        }
    }
    while(index1<=mid){
        temp.push_back(arr[index1++]);
    }
    while(index2<=high){
        temp.push_back(arr[index2++]);
    }
    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector<int>&arr,int low,int high){
    if(low>=high){
        return ;
    }
    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    mergeThem(arr,low,mid,high);
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl<<count<<endl;
}