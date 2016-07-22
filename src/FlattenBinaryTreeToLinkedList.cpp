#include "FlattenBinaryTreeToLinkedList.hpp"

#include <stack>

using namespace std;

void FlattenBinaryTreeToLinkedList::flatten(TreeNode *root) {
    TreeNode *tail = nullptr;
    flattenRec2(root, tail);
}

void FlattenBinaryTreeToLinkedList::flattenRec1(TreeNode *root) {
    if (root == nullptr)
        return;

    flattenRec1(root->left);
    flattenRec1(root->right);

    if (root->left == nullptr)
        return;

    // find the tail of left subtree
    TreeNode *tail = root->left;

    while (tail->right)
        tail = tail->right;

    // insert left subtree between root and right subtree
    tail->right = root->right;
    root->right = root->left;
    root->left = nullptr;
}

void FlattenBinaryTreeToLinkedList::flattenRec2(TreeNode *root,
                                                TreeNode *&tail) {
    if (root == nullptr)
        return;

    flattenRec2(root->right, tail);
    flattenRec2(root->left, tail);
    root->right = tail;
    root->left = nullptr;
    tail = root;
}

void FlattenBinaryTreeToLinkedList::flattenStack(TreeNode *root) {
    stack<TreeNode *> s;

    if (root != nullptr)
        s.push(root);

    while (!s.empty()) {
        TreeNode *node = s.top();
        s.pop();

        if (node->right != nullptr)
            s.push(node->right);

        if (node->left != nullptr)
            s.push(node->left);

        node->left = nullptr;
        node->right = s.empty() ? nullptr : s.top();
    }
}
