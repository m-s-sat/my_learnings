#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> sum3(vector<int> arr,int size,int K){
    vector<vector<int>> a;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            for(int k=j+1;k<size;k++){
                if(arr[i]+arr[j]+arr[k]==K){
                    vector<int> b;
                    b.push_back(arr[i]);
                    b.push_back(arr[j]);
                    b.push_back(arr[k]);
                    a.push_back(b);
                }
            }
        }
    }
    return a;
}

void printVector(vector<vector<int>> c){
    for(int i=0;i<c.size();i++){
        for(int j=0;j<c[0].size();j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int size,K;
    cin>>size>>K;
    vector<int> arr(size,0);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    vector<vector<int>> fin_al=sum3(arr,size,K);
    printVector(fin_al);
}