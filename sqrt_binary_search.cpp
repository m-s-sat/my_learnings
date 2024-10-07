#include<iostream>
using namespace std;

int sqrt_root(int n){
    int s=0;
    int e=n;
    long long int mid=s+(e-s)/2;
    long long ans =-1;
    while(s<=e){
        long long int sqr = mid*mid;
        if(sqr==n){
            return mid;
        }
        else if(sqr>n){
            e=mid-1;
        }
        else{
            ans =mid;
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans ;
}

double more_precision(int n,int k,int tempSoln){
    double temp = 1;
    double ans = tempSoln;
    for(int i=0;i<k;i++){
        temp = temp/10;
        for(double j=ans;j*j<n;j=j+temp){
            ans =j;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<sqrt_root(n);
    int tempSoln = sqrt_root(n);
    cout<<more_precision(n,4,tempSoln);
}