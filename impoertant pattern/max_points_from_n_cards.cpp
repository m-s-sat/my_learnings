#include<bits/stdc++.h>
using namespace std;

int max_points(vector<int>arr,int k){
    int right = 0,left = 0,sum = 0;
    while(right<k) sum+=arr[right++];
    right = arr.size()-1, left = k-1;
    int maxi = sum;
    while(left>=0){
        sum = sum-arr[left--]+arr[right--];
        maxi = max(maxi,sum);
    }
    return maxi;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<max_points(arr,k)<<endl;
}