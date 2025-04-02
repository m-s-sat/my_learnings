#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void max_sum_sub_array(vector<int> &nums,vector<int> &ans,int i,int sum){
    if(i>=nums.size()){
        ans.push_back(sum);
        return ;
    }
    sum+=nums[i];
    max_sum_sub_array(nums,ans,i+1,sum);
    sum-=nums[i];
    max_sum_sub_array(nums,ans,i+1,sum);
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> ans;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    max_sum_sub_array(nums,ans,0,0);
    sort(ans.begin(),ans.end());
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<ans[ans.size()-1]<<endl;
}