#include<iostream>
using namespace std;

int arraysum(int arr[],int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    return sum;
}
int main(){
    int arr[1000];
    int size;
    cout<<"give size:- ";
    cin>>size;
    cout<<"Write elements :- "<<endl;
    for(int j=0;j<size;j++){
        cin>>arr[j];
    }
    int finalsum = arraysum(arr,size);
    cout<<"Your Sum is :- "<<finalsum;
    return 0;
}