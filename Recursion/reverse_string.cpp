#include<iostream>
using namespace std;

void reverse_string(string str,int i){
    if(i>=str.size()){
        return ;
    }
    reverse_string(str,i+1);
    cout<<str[i];
}

int main(){
    string str;
    getline(cin,str);
    reverse_string(str,0);
    cout<<endl;
}