#include<iostream>
#include<vector>
using namespace std;

class Node{
public :
    int data;
    Node* prev;
    Node* next;

    Node(int value){
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList{
public:
    Node* arrayToDoublyLinkedList(vector<int>& arr){
        Node* head = new Node(arr[0]);
        Node* temp = head;

        int size = arr.size();
        for(int i = 1; i < size; i++){
            Node* newNode = new Node(arr[i]);
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode; 
        }

        return head;
    }
};



int main(){

    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};


    DoublyLinkedList dll;

    Node* head = dll.arrayToDoublyLinkedList(arr);

    cout << head->data;

    return 0;

}