#include<iostream>
#include<vector>
using namespace std;

int subarray_sum(vector<int>&nums,int target){
    int count = 0;
    for(int i=0;i<nums.size();i++){
        int sum = 0;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
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