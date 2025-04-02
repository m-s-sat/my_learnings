#include<iostream>
#include<vector>
using namespace std;

class Node{
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArrayinLL(vector<int>&nums){
    Node* head = new Node(nums[0]);
    Node* move = head;
    for(int i=1;i<nums.size();i++){
        Node* temp = new Node(nums[i]);
        move->next = temp;
        move = temp;
    }
    return head;
}

Node* deleteFirstElementFromLL(Node *head){
    if(head==NULL) return head;
    Node* temp = head;
    head = temp->next;
    free(temp);
    return head;
}

void printAllElementsOfLL(Node *head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    vector<int> nums = {12,2,3,2,1,4};
    Node* head = convertArrayinLL(nums);
    printAllElementsOfLL(head);
    head = deleteFirstElementFromLL(head);
    printAllElementsOfLL(head);
}