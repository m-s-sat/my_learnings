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
    Node* move  = head;
    for(int i=1;i<nums.size();i++){
        Node* temp = new Node(nums[i]);
        move->next = temp;
        move = temp;
    }
    return head;
}

Node* reverse(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    while(temp){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

bool check(Node* head){
    Node* temp = head;
    Node* fast = head;
    Node* slow = head;
    while(fast->next){
        if(fast->next->next==nullptr) break;
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* mid = reverse(slow->next);
    while(mid){
        if(temp->data!=mid->data) return false;
        temp = temp->next;
        mid = mid->next;
    }
    return true;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Node* head = convertArraytoLL(nums);
    head = reverse(head);
    printLL(head);
    cout<<check(head)<<endl;
}