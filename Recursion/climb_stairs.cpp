#include<iostream>
using namespace std;

int stair_ways(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    int ans = stair_ways(n-1)+stair_ways(n-2);
    return ans;
}

int main(){
    int n;
    cin>>n;
    int ans = stair_ways(n);
    cout<<ans;
}