#include<iostream>
using namespace std;

int getlength(char ch[]){
    int count=0;
    for(int i=0;ch[i]!='\0';i++){
        count+=1;
    }
    return count;
}
int main(){
    char name[1000];
    cout<<"Enter name:- ";
    cin>>name;
    cout<<"length:- "<<getlength(name);
}