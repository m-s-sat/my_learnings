#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int>& arr,int k,int mid){
    int woodCount = 1;
    int woodLength = 0;
    for(int i=0;i<arr.size();i++){
        if(woodLength + arr[i]<=mid){
            woodLength+=arr[i];
        }
        else{
            woodCount+=1;
            if(woodCount>k || arr[i]>mid){
                return false;
            }
            woodLength = arr[i];
        }
    }
    return true;
}

int max_wood(vector<int>&arr,int k){
    int s=0;
    int e = 0;
    for(auto it:arr){
        e+=it;
    }
    int mid = s+(e-s)/2;
    int ans = -1;
    while(s<=e){
        if(isPossible(arr,k,mid)){
            ans = mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
    
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<max_wood(arr,m)<<endl;
}