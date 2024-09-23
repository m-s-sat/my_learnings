#include<iostream>
#include<vector>
using namespace std;

int duplicate_element(int arr[],int size){
    int value =0;
    vector<int> a(size,0);
    for(int i=0;i<size;i++){
        a[arr[i]]++;
    }
    for(int i=1;i<a.size();i++){
        if(a[i]==2){
            value = a[i];
        }
    }
    return value;
}

int main(){
    int arr[100];
    int size;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int element = duplicate_element(arr,size);
    cout<<element; 
}