#include<iostream>
#include<vector>
using namespace std;

// Memoization
int ans(int n,vector<int>dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = ans(n-1,dp)+ans(n-2,dp);
    return dp[n];
}

// Tabulation
int f(int n,vector<int>&dp){
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    int final_ans = ans(n,dp);
    cout<<final_ans<<endl;
}