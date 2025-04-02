#include <iostream>
#include <vector>
using namespace std;

int searchRight(vector<int> &nums, int target){
    int s = 0;
    int e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s < e){
        if (nums[mid] < target){
            s=mid+1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}
int searchLeft(vector<int> &arr, int target){
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s < e){
        if (arr[mid] <= target){
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}
bool isFound(vector<int> &nums, int target){
    int s = 0;
    int e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    while (s <= e){
        if (nums[mid] == target){
            return true;
        }
        else if (nums[mid] > target){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return false;
}
vector<int> searchRange(vector<int> &nums, int target){
    vector<int> ans;
    if(ans.size()==1){
        if(nums[0]==target){
            ans.push_back(0);
            ans.push_back(0);
        }
        else{
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
    if (isFound(nums, target)){
        ans.push_back(searchRight(nums, target));
        ans.push_back(searchLeft(nums, target));
    }
    else{
        ans.push_back(-1);
        ans.push_back(-1);
    }
    return ans;
}
int main(){
    int n,target;
    cin >> n>>target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin>>nums[i];
    }
    vector<int>ans = searchRange(nums,target);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}