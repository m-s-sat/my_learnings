#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int size;
    cin>>size;
    vector<int> a(size,0);
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
    sort(a.end(),a.begin());
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}