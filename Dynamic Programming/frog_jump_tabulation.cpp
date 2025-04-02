#include<iostream>
#include<vector>
using namespace std;

int f(int n,vector<int>&dp,vector<int>&heights){
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int fs = dp[i-1] + abs(heights[i]-heights[i-1]);
        int ss = __INT_MAX__ ;
        if(i>1){
            ss = dp[i-2] + abs(heights[i]-heights[i-2]);
        }
        dp[i] = min(fs,ss);
    }
    return dp[n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> heights(n);
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }
    vector<int>dp(n+1,-1);
    cout<<f(n,dp,heights)<<endl;
}