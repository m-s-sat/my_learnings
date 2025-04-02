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

Node* odd_even(Node* head){
    vector<int> data;
    Node* temp = head;
    while(temp){
        data.push_back(temp->data);
        if(temp->next==nullptr) break;
        temp = temp->next->next;
    }
    temp = head->next;
    while(temp){
        data.push_back(temp->data);
        if(temp->next==nullptr) break;
        temp = temp->next->next;
    }
    temp = head;
    int i=0;
    while(temp){
        temp->data = data[i];
        temp = temp->next;
        i++;
    }
    return head;
}

// optimal

Node* odd_even_optimal(Node* head){
    if(head->next==nullptr) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;
    while(even!=nullptr && even->next!=nullptr){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;        
    }
    odd->next = evenHead;
    return head;
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
    head = odd_even_optimal(head);
    printLL(head);
}