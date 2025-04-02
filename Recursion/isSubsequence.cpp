#include<iostream>
using namespace std;

bool isSubsequence(string s,string t){
    int s1=0;
    int s2=0;
    while(s1<s.length()&&s2<t.length()){
        if(s[s1]==t[s2]){
            s2++;
            if(s2==t.length()){
                return true;
            }
        }
        s1++;
    }
    return false;
}

int main(){
    string s,t;
    cin>>s>>t;
    cout<<isSubsequence(s,t)<<endl;
}