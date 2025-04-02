#include<iostream>
using namespace std;

bool check_pallindrome(string str,int i){
    if(i>str.length()-i-1){
        return 1;
    }
    if(str[i]!=str[str.length()-i-1]){
        return 0;
    }
    else{
        return check_pallindrome(str,i+1);
    }

}

int main(){
    string str;
    cin>>str;
    bool temp = check_pallindrome(str,0);
    cout<<temp;
}