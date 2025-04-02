#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(vector<int>&nums,long long sum,int i,vector<long long>&temp){
    if(i>=nums.size()){
        temp.push_back(sum);
        return ;
    }
    sum+=nums[i];
    solve(nums,sum,i+1,temp);

    sum-=nums[i];
    solve(nums,sum,i+1,temp);
}

long long kSum(vector<int>&nums,int k){
    vector<long long> temp;
    solve(nums,0,0,temp);
    sort(temp.begin(),temp.end());
    return temp[temp.size()-k];
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    long long ans = kSum(nums,k);
    cout<<ans<<endl;
}