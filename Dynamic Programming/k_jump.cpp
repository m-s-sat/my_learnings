#include<iostream>
#include<vector>
using namespace std;

int f(int ind,int k,vector<int>&heights,vector<int>&dp,int temp){
    if(ind==0){
        return 0;
    }
    for(int i=1;i<=k;i++){
        if(ind>=i){
            int left = f(ind-i,k,heights,dp,temp) + abs(heights[ind]-heights[ind-i]);
            return temp = min(temp,left);
        }
    }
    return 0;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>heights(n);
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }
    int temp = __INT_MAX__;
    vector<int>dp;
    cout<<f(n,k,heights,dp,temp);
}