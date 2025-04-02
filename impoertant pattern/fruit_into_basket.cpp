#include<bits/stdc++.h>
using namespace std;

// brute force
int find_max_fruits(vector<int>nums,int k){
    int maxlength = 0;
    for(int i=0;i<nums.size();i++){
        set<int> st;
        for(int j=i;j<nums.size();j++){
            st.insert(nums[j]);
            if(st.size()>k) break;
            maxlength = max(maxlength,j-i+1);
        }
    }
    return maxlength;
}

// optimal
int find_max_fruits_optimal(vector<int>nums,int k){
    int left = 0, right = 0;
    int maxlength = 0;
    map<int,int> mp;
    while(right<nums.size()){
        if(mp.find(nums[right])==mp.end()) mp[nums[right]] = 1;
        else mp[nums[right]]++;
        if(mp.size()<=k){
            maxlength = max(maxlength,right-left+1);
        }
        else{
            while(mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0) mp.erase(nums[left]);
                left++;
            }
        }
        right++;
    }   
    return maxlength;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<nums.size();i++){
        cin>>nums[i];
    }
    cout<<find_max_fruits(nums,k)<<endl;
    cout<<find_max_fruits_optimal(nums,k)<<endl;
}