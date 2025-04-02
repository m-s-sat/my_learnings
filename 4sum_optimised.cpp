#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> foursum(vector<int>nums,int target){
    set<vector<int>> hashing;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            set<int>st;
            for(int k=j+1;k<nums.size();k++){
                int aim = target - (nums[i]+nums[j]+nums[k]);
                if(st.find(aim)!=st.end()){
                    vector<int> temp = {nums[i],nums[j],nums[k],aim};
                    sort(temp.begin(),temp.end());
                    hashing.insert(temp);
                }
                else{
                    st.insert(nums[k]);
                }
            }
        }
    }
    vector<vector<int>> ans = {hashing.begin(),hashing.end()};
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