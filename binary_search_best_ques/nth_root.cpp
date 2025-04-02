#include<iostream>
#include<math.h>
using namespace std;

int binary_search(int n,int m){
    int s=1;
    int e=n;
    int mid = (s+e)/2;
    int ans = -1;
    while(s<=e){
        if(pow(mid,m)==n) return mid;
        else if(pow(mid,n)>n) e=mid-1;
        else s=mid+1;
        mid = (s+e)/2;
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<<binary_search(n,m)<<endl;
}