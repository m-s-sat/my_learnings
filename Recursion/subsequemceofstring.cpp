#include<iostream>
#include<vector>
using namespace std;

void permutation(string &str,vector<char> &str2,int i){
    if(i>=str.length()){
        for(int i=0;i<str2.size();i++){
            cout<<str2[i];
        }
        cout<<endl;
        return ;
    }
    str2.push_back(str[i]);
    permutation(str,str2,i+1);
    str2.pop_back();
    permutation(str,str2,i+1);
}

int main(){
    string str;
    vector<char> str2;
    cin>>str;
    permutation(str,str2,0);
}