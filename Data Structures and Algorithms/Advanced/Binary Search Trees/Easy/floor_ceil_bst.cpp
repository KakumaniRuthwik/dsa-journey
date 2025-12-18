#include <iostream>
#include <vector>
using namespace std;

// BST Node Definition
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Insert into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (root == nullptr)
        return new TreeNode(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}


// Floor & Ceil in BST
vector<int> floorCeilOfBST(TreeNode* root, int key) {
    int floor = -1;
    int ceil = -1;

    TreeNode* curr = root;

    // Find floor
    while (curr != nullptr) {
        if (curr->data <= key) {
            floor = curr->data;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    curr = root;

    // Find ceil
    while (curr != nullptr) {
        if (curr->data >= key) {
            ceil = curr->data;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return {floor, ceil};
}

int main() {
    TreeNode* root = nullptr;

    vector<int> values = {8, 4, 12, 2, 6, 10, 14};
    for (int v : values)
        root = insertBST(root, v);

    int key = 11;
    vector<int> ans = floorCeilOfBST(root, key);

    cout << "Floor: " << ans[0] << endl;
    cout << "Ceil: " << ans[1] << endl;

    return 0;
}