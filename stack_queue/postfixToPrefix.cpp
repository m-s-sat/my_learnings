#include<iostream>
#include<stack>
using namespace std;

string postfixToPrefix(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')){
            string s2;
            s2.push_back(s[i]);
            st.push(s2);
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string cat = s[i]+t1+t2;
            st.push(cat);
        }
    }
    return st.top();
}

int main(){
    string s;
    cin>>s;
    cout<<postfixToPrefix(s)<<endl;
}