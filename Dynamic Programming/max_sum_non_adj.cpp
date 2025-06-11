#include<bits/stdc++.h>
using namespace std;

// meoization

int solve(vector<int>nums,int n,vector<int>dp){
    if(n==0) return nums[n];
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int pick = nums[n]+solve(nums,n-2,dp);
    int non_pick_element = solve(nums,n-1,dp);
    dp[n] = max(pick,non_pick_element);
    return dp[n];
}

// tabulation

int tablution(vector<int>nums,int n,vector<int>dp){
    dp[0] = nums[0];
    for(int i=1;i<n;i++){
        int take = nums[i];
        if(i>1) take+=dp[i-2];
        int not_take = dp[i-1];
        dp[i] = max(take,not_take);
    }
    return dp[n-1];
}

// space optimization

int space_optimised(vector<int>nums){
    int prev1 = nums[0];
    int prev2 = 0;
    for(int i=1;i<nums.size();i++){
        int take = nums[i];
        if(i>1) take+=prev2;
        int not_take = prev1;
        int curr = max(take,not_take);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> dp(n,-1);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<solve(nums,n-1,dp)<<endl<<tablution(nums,n,dp)<<endl<<space_optimised(nums);
}