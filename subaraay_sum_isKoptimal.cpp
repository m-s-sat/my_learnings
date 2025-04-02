#include<iostream>
#include<vector>
using namespace std;

int subarray_sum(vector<int>&nums,int target){
    int count = 0;
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum+=nums[k];
            }
            if(sum==target){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<subarray_sum(nums,target)<<endl;
}