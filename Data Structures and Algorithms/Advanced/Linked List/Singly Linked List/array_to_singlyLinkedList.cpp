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
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i < arr.size(); i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    return head;
}

int main(){

    vector<int> arr = {1,2,3,4,5};
    Node* head = arrayToLinkedList(arr);
    cout << head->data;

    return 0;
}