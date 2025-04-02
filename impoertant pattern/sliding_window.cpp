#include<bits/stdc++.h>
using namespace std;

// constant window problem
int max_sum(vector<int>arr,int k){
    int s = 0;
    int e = k-1;
    int sum = 0;
    while(s<=e){
        sum+=arr[s];
        s++;
    }
    s = 0;
    while(e<arr.size()){
        sum = max(sum,sum-arr[s]+arr[e]);
        e++,s++;
    }
    return sum;
}

// longest subarray / sybstring where <condition>

// better
int max_length_having_sum_k_better(vector<int>arr,int k){
    int left = 0;
    int right = left;
    int sum = 0;
    int max_length = 0;
    while(left<arr.size() && right<arr.size()){
        sum += arr[right];
        if(sum<=k){
            max_length = max(max_length,right-left+1);
            right++;
        }
        else{
            left++;
            sum -= arr[left];
            while(sum>k && left<=right){
                sum-=arr[left];
                left++;
            }
            if(left>right) left = right;
        }
    }
    return max_length;
}

// optimal
int max_length_having_sum_k_optimal(vector<int>arr,int k){
    int left = 0;
    int right = left;
    int maxlength = 0;
    int sum = 0;
    while(right<arr.size() && left<arr.size()){
        sum+=arr[right];
        if(sum<=k){
            maxlength = right-left+1;
        }
        else{
            sum-=arr[left];
            left++;
        }
        right++;
    }
    return maxlength;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<max_length_having_sum_k_better(arr,k)<<endl;
    cout<<max_length_having_sum_k_optimal(arr,k)<<endl;
}