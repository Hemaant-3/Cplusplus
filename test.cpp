#include <iostream>
#include <queue>

using namespace std;

// Structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to check if a binary tree is complete
bool isCompleteBinaryTree(TreeNode* root) {
    if (root == nullptr)
        return true;

    queue<TreeNode*> q;
    q.push(root);
    bool flag = false;

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        // If we have encountered a nullptr previously and the current node is not nullptr
        // then it's not a complete binary tree
        if (current == nullptr) {
            flag = true;
        } else {
            // If a nullptr is encountered and flag is true, then it's not a complete binary tree
            if (flag)
                return false;

            q.push(current->left);
            q.push(current->right);
        }
    }
    return true;
}

// Function to create a new binary tree node
TreeNode* newNode(int data) {
    TreeNode* node = new TreeNode(data);
    return node;
}

int main() {
    // Creating a binary tree
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    if (isCompleteBinaryTree(root))
        cout << "The binary tree is a complete binary tree." << endl;
    else
        cout << "The binary tree is not a complete binary tree." << endl;

    return 0;
}
