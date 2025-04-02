#include<iostream>
#include<stack>
using namespace std;

string prefixToinfix(string s){
    int e = s.length()-1;
    stack<string> st;
    while(e>=0){
        if((s[e]>='a'&&s[e]<='z')||(s[e]>='A'&&s[e]<='Z')||(s[e]>='0'&&s[e]<='9')){
            string s1;
            s1.push_back(s[e]);
            st.push(s1);
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string cat = '('+t1+s[e]+t2+')';
            st.push(cat); 
        }
        e--;
    }
    return st.top();
}

int main(){
    string s;
    cin>>s;
    cout<<prefixToinfix(s)<<endl;
}