#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>valueInHouses){
    if(n==0) return valueInHouses[n];
    if(n==1) return 0;
    int pick = valueInHouses[n] + solve(n-2,valueInHouses);
    int non_pick = solve(n-1,valueInHouses);
    return max(pick,non_pick);
}

int main(){
    int n;
    cin>>n;
    vector<int> valueInhouses(n);
    for(int i=0;i<n;i++) cin>>valueInhouses[i];
    cout<<solve(n-1,valueInhouses);
}