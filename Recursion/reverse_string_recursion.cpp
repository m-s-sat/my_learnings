#include<iostream>
using namespace std;

void reversed(string &arr,int s,int e){
    if(s>e){
        return ; 
    }
    swap(arr[s],arr[e]);
    reversed(arr,s+1,e-1);
}

int main(){
    string arr;
    cin>>arr;
    reversed(arr,0,arr.length()-1);
    cout<<arr;
}