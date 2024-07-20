#include<iostream>
using namespace std;

char maximum_letter(string s){
    int arr[26]={0};
    for(int i=0;i<s.length();i++){
        int n = s[i]-'a';
        arr[n]++;
    }
    int maxi = -1;
    int ans =0;
    for(int i=0;i<26;i++){
        if(maxi<arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }
    return ans+'a';
}

int main(){
    string name;
    cin>>name;
    cout<<maximum_letter(name);
}