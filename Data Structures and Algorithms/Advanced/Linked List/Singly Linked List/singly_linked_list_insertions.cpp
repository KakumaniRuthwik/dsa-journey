#include<iostream>
#include<vector>

using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

Node* arrayToLinkedList(vector<int>& arr){
    
    int size = arr.size();

    if(size == 0){
        return nullptr;
    }

    Node* head = new Node(arr[0]);
    Node* temp = head;
    
    for(int i = 1; i < size; i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    return head;
}

void linkedListTraversal(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp -> next;
    }

    cout << "NULL";
}

void insertAtBeginning(Node* &head,int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void 

int main(){

    vector<int> arr = {10,9,8,7,6,5,4,3,2,1};

    Node* head = arrayToLinkedList(arr);
    
    cout << endl;
    
    cout << "Linked List before adding Elements at beginning : " ;
    linkedListTraversal(head);
    
    cout << endl;
    
    cout << "Linked List after adding Elements at beginning : " ;
    linkedListTraversal(head);

    return 0;
}