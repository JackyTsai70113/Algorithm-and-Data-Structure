/**
 * LeetCode Problem: 101. Symmetric Tree
 * 
 * Given a binary tree, check whether it is a mirror of itself
 * (ie, symmetric around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 *                1
 *               / \
 *              2   2
 *             / \ / \
 *            3  4 4  3
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 *                1
 *               / \
 *              2   2
 *               \   \
 *               3    3
 */

#include <iostream>
#include <stack>

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode():left(0), right(0), val(0){};
    TreeNode(int x):left(0), right(0), val(x){};
};

bool isSymmetric_from_iteration(TreeNode* root) {
        
    if (!root) return true;
    
    std::stack<TreeNode*> s;
    if (root->left) s.push(root->left);
    if (root->right) s.push(root->right);
    
    while (!s.empty()) {
        
        if(s.size() % 2 != 0) return false;
        
        TreeNode* left = s.top();
        s.pop();
        TreeNode* right = s.top();
        s.pop();
        
        if (left->val != right->val) return false;
        
        if (left->left) s.push(left->left);
        if (right->right) s.push(right->right);
        
        if(s.size() % 2 != 0) return false;
        
        if (left->right) s.push(left->right);
        if (right->left) s.push(right->left);
    }
    return true; 
}

bool isSymmetric_recursive(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (left && right && left->val == right->val) 
        return (isSymmetric_recursive(left->left, right->right) && 
                isSymmetric_recursive(left->right, right->left));
    return false;
}

bool isSymmetric_from_recursion(TreeNode* root) {
    return (!root || isSymmetric_recursive(root->left, root->right));   
}

int main() {
    TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(3);
	std::cout << isSymmetric_from_iteration(root) << std::endl;
    std::cout << isSymmetric_from_recursion(root) << std::endl;
	return 0;
}