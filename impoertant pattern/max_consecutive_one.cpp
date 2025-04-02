#include<bits/stdc++.h>
using namespace std;

// brute force
int max_consecutive_one(vector<int>arr,int k){
    int maxlength = 0;
    for(int i=0;i<arr.size();i++){
        int zeros = 0;
        for(int j=i;j<arr.size();j++){
            if(arr[j]==0) zeros++;
            if(zeros<=k){
                maxlength = max(maxlength,j-i+1);
            }
            if(zeros>k) break;
        }
    }
    return maxlength;
}

// optimal
int max_consecutive_one_optimal(vector<int>arr,int k){
    int left = 0,right = 0;
    int maxlength = 0;
    int zeros = 0;
    while(right<arr.size()){
        if(arr[right]==0) zeros++;
        if(zeros<=k) maxlength = max(maxlength,right-left+1);
        else{
            while(left<right && zeros>k){
                if(arr[left]==0) zeros--;
                left++;
            }
        }
        right++;
    }
    return maxlength;
}

// most optimal
int max_consecutive_one_most_optimal(vector<int>&arr,int k){
    int left = 0, right = 0;
    int maxlength = 0;
    int zeros = 0;
    while(right<arr.size()){
        if(arr[right]==0) zeros++;
        if(zeros<=k){
            maxlength = max(maxlength,right-left+1);
        }
        else{
            if(arr[left]==0) zeros--;
            left++;
        }
        right++;
    }
    return maxlength;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<max_consecutive_one(arr,k)<<endl;
    cout<<max_consecutive_one_optimal(arr,k)<<endl;
    cout<<max_consecutive_one_most_optimal(arr,k)<<endl;
}