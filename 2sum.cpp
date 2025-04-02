#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> sum2(vector<int>nums,int k){
    vector<vector<int>> ans;
    set<vector<int>> storing;
    set<int>st;
    for(int i=0;i<nums.size();i++){
        int taregt = k-nums[i];
        if(st.find(taregt)!=st.end()){
            vector<int>temp = {nums[i],taregt};
            sort(temp.begin(),temp.end());
            storing.insert(temp);
        }
        else{
            st.insert(nums[i]);
        }
    }
    ans = {storing.begin(),storing.end()};
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>>ans = sum2(nums,k);
    for(int i=0;i<ans.size();i++){
        for(int k=0;k<2;k++){
            cout<<ans[i][k]<<" ";
        }
        cout<<endl;
    }
}