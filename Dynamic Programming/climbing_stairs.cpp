#include<iostream>
#include<vector>
using namespace std;

int solve(long long n,vector<int>&dp){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = solve(n-2,dp) + solve(n-1,dp);
    return dp[n];
}

int countNumberOfWays(long long n){
    vector<int> dp(n+1,-1);
    return solve(n,dp);
}

int main(){
    long long n;
    cin>>n;
    int ans = countNumberOfWays(n);
    cout<<ans<<endl;
}