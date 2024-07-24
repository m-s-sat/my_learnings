#include<iostream>
using namespace std;

void sortOnearray(int arr[],int n){
    int left=0, right = n-1;
    while(left<=right){
        while(arr[left]==0){
            left++;
        }
        while(arr[right]==1){
            right--;
        }
        swap(arr[left],arr[right]);
        left++, right--;
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[8]={1,1,0,0,0,0,1,0};
    sortOnearray(arr,8);
    printArray(arr,8);
}