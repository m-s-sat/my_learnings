#include<bits/stdc++.h>
using namespace std;

int countSubarraySum(vector<int>nums,int k){
    map<int,int> mp;
    mp[0] = 1;
    int ans = 0;
    int sum = 0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        int diff = sum-k;
        ans+=mp[diff];
        mp[sum]+=1;
    }
    return ans;
}
// brute force
int countSubarraySumBrutrForce(vector<int>&nums,int k){
    int ans = 0;
    for(int i=0;i<nums.size();i++){
        int sum = 0;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            if(sum==k) ans++;
        }
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<nums.size();i++){
        cin>>nums[i];
    }
    cout<<countSubarraySum(nums,k)<<endl;
    cout<<countSubarraySumBrutrForce(nums,k)<<endl;
}