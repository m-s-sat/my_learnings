#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cookies_assign(vector<int>& greedy, vector<int>& cookies){
    sort(greedy.begin(),greedy.end());
    sort(cookies.begin(),cookies.end());
    int l = 0;
    int r = 0;
    while(l<cookies.size()){
        if(greedy[r]<=cookies[l]) r=r+1;
        l++;
    }
    return r;
}

int main(){
    int n;
    cin>>n;
    vector<int> greedy(n);
    int m;
    cin>>m;
    vector<int> cookies(m);
    for(int i=0;i<n;i++){
        cin>>greedy[i];
    }
    for(int i=0;i<m;i++){
        cin>>cookies[i];
    }
    cout<<cookies_assign(greedy,cookies)<<endl;
}