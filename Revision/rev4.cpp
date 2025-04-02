#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> sum_find_3(vector<int>&nums){
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int s=i+1;
        int e=nums.size()-1;
        while(s<e){
            if(nums[i]+nums[s]+nums[e]>0){
                e--;
            }
            else if(nums[i]+nums[s]+nums[e]<0){
                s++;
            }
            else{
                vector<int> temp = {nums[i],nums[s],nums[e]};
                ans.push_back(temp);
                s++;
                e--;
                while(s<e && nums[s]==nums[s-1]){
                    s++;
                }
                while(s<e && nums[e]==nums[e+1]){
                    e--;
                }
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>> ans = sum_find_3(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}