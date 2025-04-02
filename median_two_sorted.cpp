#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double findMedianSortedArray(vector<int> nums1,vector<int> nums2){
    for(int i=0;i<nums2.size();i++){
        nums1.push_back(nums2[i]);
    }
    sort(nums1.begin(),nums1.end());
    double ans;
    if(nums1.size()&1){
        ans = nums1[nums1.size()/2];
    }
    else{
        int a = nums1.size()/2;
        ans = (nums1[a]+nums1[a-1])/2.0;
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n;
    vector<int> nums1(n);
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    cin>>m;
    vector<int> nums2(m);
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }
    double ans = findMedianSortedArray(nums1,nums2);
    cout<<ans<<endl;
}