#include<iostream>
#include<vector>
using namespace std;

int count(vector<int>arr){
    int count=0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]<arr[j]){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<count(arr)<<endl;
}