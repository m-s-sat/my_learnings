#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> &arr,int mid){
    int s = 0;
    int e = arr.size()-1;
    while(s<arr.size()&&e>=0){
        if(abs(arr[s]-arr[e])>=mid){
            return true;
        }
        else{

        }
    }
}

int largest_distance(vector<int> &arr,int k){
    sort(arr.begin(),arr.end());
    int s = 0;
    int maxi = arr[0];
    int mini = arr[0];
    for(auto it:arr){
        if(mini>it){
            mini = it;
        }
        if(maxi<it){
            maxi = it;
        }
    }
    int e = maxi - mini;
    int mid  = s+(e-s)/2;
    int ans = -1;
    while(s<=e){
        if(isPossible(arr,mid,k)){
            ans = mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = largest_distance(arr,k);
}