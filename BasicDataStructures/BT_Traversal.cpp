#include <iostream>
#include <string>
#include <queue>

class BinaryTree;

class TreeNode{
public:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    std::string str;
    TreeNode():leftchild(0), rightchild(0), parent(0), str(""){};
    TreeNode(std::string s):leftchild(0), rightchild(0), parent(0), str(s){};
    friend class BinaryTree;
};

class BinaryTree{
public:
    TreeNode *root;
    
    BinaryTree():root(0){};
    BinaryTree(TreeNode *node):root(node){};

    void Preorder(TreeNode *current);
    void Inorder(TreeNode *current);
    void Postorder(TreeNode *current);
    void LevelOrder();

    TreeNode* leftmost(TreeNode *current);   // 尋找以current為root之subtree中，最左邊的node。
    TreeNode* rightmost(TreeNode *current);  // 尋找以current為root之subtree中，最右邊的node。

    TreeNode* InorderSuccessor(TreeNode *current);   //找到下一個 rightchild的leftmost or 以leftchild身份找到的ancestor
    TreeNode* InorderPredecessor(TreeNode *current); //找到上一個 leftchild的rightmost or 以rightchild身份找到的ancestor

    void Inorder_by_parent(TreeNode *root);
    void Inorder_Reverse(TreeNode *root);
};
void BinaryTree::Preorder(TreeNode *current){

    if (current) {
        std::cout << current->str << " ";
        Preorder(current->leftchild);
        Preorder(current->rightchild);
    }
}
void BinaryTree::Inorder(TreeNode *current){

    if (current) {
        Inorder(current->leftchild);
        std::cout << current->str << " ";
        Inorder(current->rightchild);
    }
}
void BinaryTree::Postorder(TreeNode *current){

    if (current) {
        Postorder(current->leftchild);
        Postorder(current->rightchild);
        std::cout << current->str << " ";
    }
}
void BinaryTree::LevelOrder(){
    
    std::queue<TreeNode*> q;
    q.push(this->root);

    while (!q.empty()) {

        TreeNode *current = q.front();
        q.pop();
        std::cout << current->str << " ";

        if(current->leftchild != NULL)
            q.push(current->leftchild);
        if(current->rightchild != NULL)
            q.push(current->rightchild);

    }
}
TreeNode* BinaryTree::leftmost(TreeNode *current){

    if (current == NULL) {
        std::cout << "The node is NULL." << std::endl;
        return 0;
    }

    while (current->leftchild)
        current = current->leftchild;
    return current;
}
TreeNode* BinaryTree::rightmost(TreeNode *current){

    if (current == NULL) {
        std::cout << "The node is NULL." << std::endl;
        return 0;
    }

    while(current->rightchild)
        current = current->rightchild;
    return current;
}

TreeNode* BinaryTree::InorderSuccessor(TreeNode *current){

    if (current == NULL) {
        std::cout << "The node is NULL." << std::endl;
        return 0;
    }


    if (current->rightchild != NULL)
        return leftmost(current->rightchild);

    while (current->parent != NULL && current == current->parent->rightchild) {
        current = current->parent;
    }
    return current->parent;
}  
TreeNode* BinaryTree::InorderPredecessor(TreeNode *current){
    
    if (current == NULL) {
        std::cout << "This node is NULL." << std::endl;
        return 0;
    }

    if (current->leftchild != NULL)
        return rightmost(current->leftchild);
    
    while (current->parent != NULL && current == current->parent->leftchild)
        current = current->parent;
    return current->parent;
}

void BinaryTree::Inorder_by_parent(TreeNode *root){
    
    TreeNode *current = new TreeNode;
    current = leftmost(root);

    while (current) {
        std::cout << current->str << " ";
        current = InorderSuccessor(current);
    }
}
void BinaryTree::Inorder_Reverse(TreeNode *root){
    
    TreeNode *current = new TreeNode;
    current = rightmost(root);

    while (current) {
        std::cout << current->str << " ";
        current = InorderPredecessor(current);
    }
}
int main() {
    // TreeNode instantiation
    TreeNode *nodeA = new TreeNode("A"); TreeNode *nodeB = new TreeNode("B");
    TreeNode *nodeC = new TreeNode("C"); TreeNode *nodeD = new TreeNode("D");
    TreeNode *nodeE = new TreeNode("E"); TreeNode *nodeF = new TreeNode("F");
    TreeNode *nodeG = new TreeNode("G"); TreeNode *nodeH = new TreeNode("H");
    TreeNode *nodeI = new TreeNode("I");

    // construct the Binary Tree
    nodeA->leftchild = nodeB; nodeA->rightchild = nodeC;
    nodeB->leftchild = nodeD; nodeB->rightchild = nodeE;
    nodeE->leftchild = nodeG; nodeE->rightchild = nodeH;
    nodeC->leftchild = nodeF; nodeF->rightchild = nodeI;

     // link parent pointer
    nodeB->parent = nodeA; nodeC->parent = nodeA;
    nodeD->parent = nodeB; nodeE->parent = nodeB;
    nodeG->parent = nodeE; nodeH->parent = nodeE;
    nodeF->parent = nodeC; 
    nodeI->parent = nodeF;

    BinaryTree T(nodeA);

    T.Preorder(T.root);
    std::cout << " : Preorder" << std::endl;
    T.Inorder(T.root);
    std::cout << " : Inorder" << std::endl;
    T.Postorder(T.root);
    std::cout << " : Postorder" << std::endl;
    T.LevelOrder();
    std::cout << " : Levelorder" << std::endl;

    T.Inorder_by_parent(T.root);
    std::cout << " : Inorder_by_parent" << std::endl;
    T.Inorder_Reverse(T.root);
    std::cout << " : Inorder_Reverse" << std::endl;

    return 0;
}