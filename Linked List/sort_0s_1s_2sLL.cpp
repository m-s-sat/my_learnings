#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    public:
        Node(int data1,Node* next1){
            data = data1;
            next = next1;
        }
    public:
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* convertArraytoLL(vector<int>&nums){
    Node* head = new Node(nums[0]);
    Node* move = head;
    for(int i=1;i<nums.size();i++){
        Node* temp = new Node(nums[i]);
        move->next = temp;
        move = temp;
    }
    return head;
}

// brute force

Node* sort(Node* head){
    vector<int> data;
    Node* temp = head;
    while(temp){
        if(temp->data==0) data.push_back(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp){
        if(temp->data==1) data.push_back(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp){
        if(temp->data==2) data.push_back(temp->data);
        temp = temp->next;
    }
    temp = head;
    int i = 0;
    while(temp){
        temp->data = data[i];
        temp = temp->next;
        i++;
    }
    return head;
}

// optimal

Node* sort_optimal(Node* head){
    if(head->next==nullptr) return head;
    Node* zeroNode = new Node(-1);
    Node* oneNode = new Node(-1);
    Node* twoNode = new Node(-1);
    Node* zero = zeroNode;
    Node* one = oneNode;
    Node* two = twoNode;
    Node* temp = head;
    while(temp){
        if(temp->data==0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data==1){
            one->next = temp;
            one = temp;
        }
        else{
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = oneNode->next;
    if(zero->next==nullptr) zero->next=twoNode->next;
    else one->next = twoNode->next;
    two->next = nullptr;
    Node* newHead = zeroNode->next;
    free(zeroNode);
    free(oneNode);
    free(twoNode);
    return newHead;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Node* head = convertArraytoLL(nums);
    head = sort_optimal(head);
    printLL(head);
}