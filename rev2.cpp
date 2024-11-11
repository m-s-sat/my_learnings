#include<iostream>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    int c=0;
    for(int i=str.length()-c-1;i>=0;i--){
        if(str[i]!=' '){
            c++;
        }
        else{
            for(int j=str.length()-c-1;j<str.length()-1;j++){
                cout<<str[j];
            }
        }
    }
}