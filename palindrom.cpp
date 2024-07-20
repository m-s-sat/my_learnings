#include<iostream>
using namespace std;

int small_character(char ch){
    if(ch>='A'&&ch<='Z'){
        char new_ch = ch-'A'+'a';
        return new_ch;
    }
    else if((ch>='a'&&ch<='z')||(ch>='0'&&ch<='9')){
        return ch;
    }
    else{
        return 0;
    }
}
int check_pallindrom(char name[],int size){
    int s=0;
    int e=size-1;
    while(s<e){
        if(small_character(name[s])==0){
            s++;
            continue;
        }
        else if(small_character(name[e])==0){
            e--;
            continue;
        }
        else if(small_character(name[s])!=small_character(name[e])){
            return 0;
        }
        s++;
        e--;
    }
    return 1;
    
}
int main(){
    char name[100];
    int size;
    cout<<"Word length:- ";
    cin>>size;
    cout<<"Name ";
    cin>>name;
    if(check_pallindrom(name,size)==0){
        cout<<"no";
    }
    else{
        cout<<"yes";
    }  
}