#include <iostream>
#include <sstream>
#include <queue>

class BinaryTree;
class TreeNode{
private:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    char data;
public:
    TreeNode():leftchild(0), rightchild(0), parent(0), data('\0'){};
    TreeNode(char c):leftchild(0), rightchild(0), parent(0), data(c){};

    friend class BinaryTree;
};

class BinaryTree{
private: 
    TreeNode *root;
public:
    BinaryTree():root(0){};
    BinaryTree(const char* str);

    void LevelorderConstruct(std::stringstream &ss);
    void InsertLevelorder(char data);

    TreeNode *leftmost(TreeNode *current);
    TreeNode *InorderSuccessor(TreeNode *current);
    void Inorder_by_parent();
};

BinaryTree::BinaryTree(const char* str){
    
    std::stringstream ss;
    ss << str;

    root = new TreeNode;
    ss >> root->data;
    LevelorderConstruct(ss);
}
void BinaryTree::LevelorderConstruct(std::stringstream &ss){
    std::queue<TreeNode*> q;
    TreeNode *current = root;
    char data = 'x';

    while (ss >> data) {
        if (data >= 65 && data <= 90) {
            TreeNode *left = new TreeNode(data);
            left->parent = current;
            current->leftchild = left;
            q.push(left);
        }

        if(!(ss >> data)) break;

        if (data >= 65 && data <= 90) {
            TreeNode *right = new TreeNode();
            right->data = data;
            right->parent = current;
            current->rightchild = right;
            q.push(right);
        }

        current = q.front();
        q.pop();
    }
}
void BinaryTree::InsertLevelorder(char data){

    std::queue<TreeNode*> q;
    TreeNode *current = root;

    while (current) {
        if (!current->leftchild) {
            TreeNode *new_node = new TreeNode(data);
            new_node->parent = current;
            current->leftchild = new_node;
            break;
        }
        else {
            q.push(current->leftchild);
        }

        if (!current->rightchild) {
            TreeNode *new_node = new TreeNode(data);
            new_node->parent = current;
            current->rightchild = new_node;
            break;
        }
        else {
            q.push(current->rightchild);
        }

        current = q.front();
        q.pop();
    }
}

TreeNode* BinaryTree::leftmost(TreeNode* current){
    
    while (current->leftchild)
        current = current->leftchild;
    return current;
}

TreeNode* BinaryTree::InorderSuccessor(TreeNode *current){
    
    if (current->rightchild)
        return leftmost(current->rightchild);
    
    while (current->parent && current == current->parent->rightchild) {
        current = current->parent;
    }
    return current->parent;
}

void BinaryTree::Inorder_by_parent(){
    
    TreeNode *current = new TreeNode;
    current = leftmost(root);
    while (current) {
        std::cout << current->data << " ";
        current = InorderSuccessor(current);
    }
}
int main() {
    const char *a = "A B C D E F x x x G H x I";
    BinaryTree T(a);
    T.Inorder_by_parent();
    std::cout << std::endl;

    T.InsertLevelorder('K');
    T.InsertLevelorder('L');
    T.InsertLevelorder('M');
    T.InsertLevelorder('N');
    T.Inorder_by_parent();
    std::cout << std::endl;

    return 0;
}