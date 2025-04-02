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

Node* deleteKelement(Node* head,int k){
    if(head==nullptr) return nullptr;
    if(k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Node* head = convertArrayintoLL(nums);
    cout<<"Before erasing ";
    printLL(head);
    head = deleteKelement(head,k);
    cout<<"After erasing ";
    printLL(head);
}