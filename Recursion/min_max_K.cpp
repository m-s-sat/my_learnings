#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

void f(vector<int>&nums,vector<int>temp,int k,int &ans,int i,int modulo){
    if(i>=nums.size()){
        if(k>=temp.size()){
            int mini = INT32_MAX;
            int maxi = INT16_MAX;
            for(int j=0;j<temp.size();j++){
                if(nums[j]>maxi) maxi = nums[j];
                if(nums[j]<mini) mini = nums[j];
            }
            ans+=(mini+maxi)%modulo;
        }
        return ; 
    }
    temp.push_back(nums[i]);
    f(nums,temp,k,ans,i+1,modulo);
    temp.pop_back();
    f(nums,temp,k,ans,i+1,modulo);

}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans = 0;
    vector<int>temp;
    f(nums,temp,k,ans,0,1000000007);
    cout<<ans+1<<endl;
}