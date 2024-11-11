#include<iostream>
#include<vector>
using namespace std;

int getLongestSubarray(vector<int>& arr,int k){
    int count = 0;
    
}

int main(){
    int size,k;
    cin>>size>>k;
    vector<int> arr(size,0);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int ans = getLongestSubarray(arr,k);
    cout<<ans;
}