#include<iostream>
#include<math.h>
using namespace std;

int nearest_square(int n,int s,int e){
    int mid = s+(e-s)/2;
    if(s>=e){
        return mid;
    }
    if(mid*mid>n){
        return nearest_square(n,s,mid-1);
    }
    else{
        return nearest_square(n,mid+1,e);
    }
}

float decimal_ans(int n,int k,int ans){
    double factor = 1;
    double ans1 = ans;
    for(int i=0;i<k;i++){
        factor=factor/10;
        for(double j=ans1;j*j<n;j+=factor){
            ans1= j;
        }
    }
    return ans1;
}

int main(){
    int n,k;
    cin>>n>>k;
    int nearest_integer = nearest_square(n,0,n);
    int ans = nearest_integer;
    double final_ans = decimal_ans(n,k,ans);
    cout<<final_ans<<endl;
}