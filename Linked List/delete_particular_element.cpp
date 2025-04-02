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

Node* deleteElemetntbyVal(Node* head,int val){
    if(head==nullptr) return head;
    if(head->data==val){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *temp = head;
    Node* prev = nullptr;
    while(temp!=nullptr){
        if(temp->data==val){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

void printNode(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    int n,val;
    cin>>n>>val;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Node* head = convertArrayinLL(nums);
    cout<<"Before Deletion : ";
    printNode(head);
    head = deleteElemetntbyVal(head,val);
    cout<<"After Deletion : ";
    printNode(head);
}