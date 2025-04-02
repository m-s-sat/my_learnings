#include<iostream>
#include<vector>
using namespace std;

int solve(int n,vector<int>&energy,vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int left = solve(n-1,energy,dp) + abs(energy[n]-energy[n-1]);
    int right = __INT_MAX__;
    if(n>1){
        right = solve(n-2,energy,dp) + abs(energy[n]-energy[n-2]);
    }
    return dp[n]=min(left,right);
}

int minEnergyForFrog(int n){
    vector<int>energy(n);
    vector<int>dp(n+1,-1);
    for(int i=0;i<n;i++){
        cin>>energy[i];
    }
    return solve(n-1,energy,dp);
}

int main(){
    int n;
    cin>>n;
    cout<<minEnergyForFrog(n)<<endl;

}