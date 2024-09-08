#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int size,key;
    vector<int> a(size,0);
    cin>>size>>key;
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
    int count =0;
    for(int i=0;i<size;i++){
        if(a[i]==key){
            a.erase(a.begin()+i);
            count++;
        }
    }
    cout<<count;
    for(int i=0;i<(size-count);i++){
        cout<<a[i]<<" ";
    }
}