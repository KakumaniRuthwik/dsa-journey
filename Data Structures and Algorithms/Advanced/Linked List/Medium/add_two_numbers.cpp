#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummy->next;
    }
};

// Utility function: Print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Utility function: Insert node at end
ListNode* insert(ListNode* head, int val) {
    if (!head) return new ListNode(val);

    ListNode* temp = head;
    while (temp->next) temp = temp->next;

    temp->next = new ListNode(val);
    return head;
}

int main() {
    // Example: l1 = [2,4,3]  (means 342)
    ListNode* l1 = nullptr;
    l1 = insert(l1, 2);
    l1 = insert(l1, 4);
    l1 = insert(l1, 3);

    // Example: l2 = [5,6,4]  (means 465)
    ListNode* l2 = nullptr;
    l2 = insert(l2, 5);
    l2 = insert(l2, 6);
    l2 = insert(l2, 4);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result Linked List: ";
    printList(result);   // Expected: 7 -> 0 -> 8

    return 0;
}
