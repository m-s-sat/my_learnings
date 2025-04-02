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

Node* deleteElfromLast(Node* head,int k){
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    if(cnt<k) return head;
    else if(cnt==k){
        temp = head;
        head = head->next;
        free(temp);
    }
    else{
        cnt = cnt-k+1;
        temp = head;
        Node* prev = nullptr;
        while(temp){
            cnt--;
            if(cnt==0){
                prev->next = prev->next->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

// optimal

Node* deleteNodefromLast(Node* head,int k){
    if(head==nullptr) return head;
    if(k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt  = 0;
    Node* fast = head;
    while(fast){
        cnt++;
        if(cnt==k) break;
        fast = fast->next;
    }
    Node* last = head;
    Node* prev = nullptr;
    while(fast->next){
        prev = last;
        fast = fast->next;
        last = last->next;
    }
    prev->next = prev->next->next;
    free(last);
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
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Node* head = convertArraytoLL(nums);
    head = deleteNodefromLast(head,k);
    printLL(head);
}