#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    public:
        Node(int data1,Node*next1){
            data = data1;
            next = next1;
        }
    public:
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* convertArrayintoLL(vector<int>&nums){
    Node* head = new Node(nums[0]);
    Node* move = head;
    for(int i=1;i<nums.size();i++){
        Node* temp = new Node(nums[i]);
        move->next = temp;
        move = temp;
    }
    return head;
}

Node* addElementBeforeVal(Node* head,int el,int val){
    if(head==nullptr){
        return head;
    }
    if(head->data==val){
        return new Node(el,head->next);
    }
    Node* temp = head;
    while(temp->next!=nullptr){
        if(temp->next->data==val){
            Node* newNode = new Node(el,temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
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
    int n,val,el;
    cin>>n>>val>>el;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Node* head = convertArrayintoLL(nums);
    head = addElementBeforeVal(head,el,val);
    printLL(head);
}