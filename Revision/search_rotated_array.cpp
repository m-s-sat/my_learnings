#include<iostream>
#include<vector>
using namespace std;

int pivot_element(vector<int> &nums){
    int s=0;
    int e=nums.size()-1;
    int mid = s+(e-s)/2;
    while(s<e){
        if(nums[mid]<=nums[0]){
            e=mid;
        }
        else{
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
    return s;
}

int search_left(vector<int> &nums,int target,int pivot){
    int s=0;
    int e=pivot-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

int search_right(vector<int> &nums,int target,int pivot){
    int s=pivot;
    int e= nums.size()-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

int search(vector<int>&nums,int target){
    int pivot = pivot_element(nums);
    if(target>=nums[0]){
        return search_left(nums,target,pivot);
    }
    else{
        return search_right(nums,target,pivot);
    }
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<search(nums,target)<<endl<<pivot_element(nums)<<endl;
}