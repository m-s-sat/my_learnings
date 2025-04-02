#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> foursum(vector<int>&nums,int target){
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i=0;i<nums.size();i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        for(int j=i+1;j<nums.size();j++){
            if(j>i+1 && nums[j]==nums[j-1]){
                continue;
            }
            int k=j+1;
            int l=nums.size()-1;
            while(k<l){
                long long sum = nums[i];
                sum+=nums[j];
                sum+=nums[k];
                sum+=nums[l];
                if(sum>target){
                    l--;
                }
                else if(sum<target){
                    k++;
                }
                else{
                    vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1]){
                        k++;
                    }
                    while(k<l && nums[l]==nums[l+1]){
                        l--;
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>> ans = foursum(nums,target);
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<4;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}