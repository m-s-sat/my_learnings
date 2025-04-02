#include<bits/stdc++.h>
using namespace std;

// only positive element in array

int longestSubarrayhavingonlypositivelement(vector<int>arr,int k){
    int left = 0;
    int right = left;
    int ans = 0;
    int sum = 0;
    while(right<arr.size()){
        sum+=arr[right];
        if(sum==k){
            ans = max(ans,right-left+1);
            sum-=arr[left];
            left++;
        }
        else if(sum>k){
            sum-=left;
            left++;
        }
        right++;
    }
    return ans;
}
// for both +ves and -ves integer value

int longestsubaarayusingmap(vector<int>&arr,int k){
    map<int,int> mp;
    int sum = 0;
    int len = 0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum==k) len = i+1;
        int diff = sum-k;
        if(mp.find(diff)!=mp.end()) len = max(len,i-mp[diff]);
        if(mp.find(sum)==mp.end()) mp[sum] = i;
    }
    return len;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i =0;i<n;i++) cin>>arr[i];
    cout<<longestSubarrayhavingonlypositivelement(arr,k)<<endl;
    cout<<longestsubaarayusingmap(arr,k)<<endl;
}