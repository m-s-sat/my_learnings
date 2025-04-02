#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArrayToLL(vector<int>&nums){
    Node* head = new Node(nums[0]);
    Node* mover = head;
    for(int i=1;i<nums.size();i++){
        Node* temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}

bool checkElementinLL(int n,Node*head){
    Node*temp = head;
    while(temp){
        if(temp->data==n){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    vector<int>nums = {12,2,3,2,1,3};
    int n;
    cin>>n;
    Node* head = convertArrayToLL(nums);
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    cout<<"Length of LL is : "<<lengthOfLL(head)<<endl;
    cout<<checkElementinLL(n,head)<<endl;
}