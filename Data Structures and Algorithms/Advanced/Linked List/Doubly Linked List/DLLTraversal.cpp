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
    Node* head;
    Node* tail;

    Node* arrayToDoublyLinkedList(vector<int>& arr){
        head = new Node(arr[0]);
        Node* temp = head;

        int size = arr.size();
        for(int i = 1; i < size; i++){
            Node* newNode = new Node(arr[i]);
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode; 
        }

        tail = temp;
        return head;
    }

    void displayForward(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "Null";
    }

    void displayBackward(Node* tail){
        Node* temp = tail;
        while(temp != nullptr){
            cout << temp -> data << "->";
            temp = temp->prev;
        }

        cout << "Null";
    }
};



int main(){

    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};


    DoublyLinkedList dll;

    Node* head = dll.arrayToDoublyLinkedList(arr);

    cout << "Traversal from head : ";
    dll.displayForward(head);

    cout << endl;
    cout << "Traversal from tail : ";
    dll.displayBackward(dll.tail);

    return 0;

}