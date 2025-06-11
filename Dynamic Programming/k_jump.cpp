#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>heights,int n,int k,vector<int>dp){
    if(n==0) return 0;
    int min_energy = INT_MAX;
    for(int i=1;i<=k;i++){
        if(i<=n){
            if(dp[n]!=-1) return dp[n];
            int jump = solve(heights,n-i,k,dp)+abs(heights[n]-heights[n-i]);
            min_energy = min(min_energy,jump);
        }
    }
    dp[n] = min_energy;
    return dp[n];
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> heights(n);
    vector<int> dp(n+1,-1);
    for(int i=0;i<n;i++) cin>>heights[i];
    cout<<solve(heights,n-1,k,dp);
}