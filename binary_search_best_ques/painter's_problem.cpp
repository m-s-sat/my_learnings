#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &arr,int mid,int m){
    int distance = 0;
    int paintersCount = 1;
    for(auto it:arr){
        if(distance + it <=mid){
            distance+=it;
        }
        else{
            paintersCount++;
            if(paintersCount>m || it>mid){
                return false;
            }
            distance = it;
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &arr,int m){
    int s = 0;
    int e = 0;
    for(auto it:arr){
        e+=it;
    }
    int mid = s+(e-s)/2;
    int ans = -1;
    while(s<=e){
        if(isPossible(arr,mid,m)){
            e = mid-1;
            ans = mid;
        }
        else{
            s= mid+1;
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
    int ans = findLargestMinDistance(arr,m);
    cout<<ans<<endl;
}