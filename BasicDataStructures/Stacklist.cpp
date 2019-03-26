#include <iostream>
class StackList;

class StackNode{
private:
    int data;
    StackNode *next;
public:
    StackNode():data(0), next(0){};
    StackNode(int x):data(x), next(0){};
    StackNode(int x, StackNode *nextNode):data(x), next(nextNode){};

    friend class StackList;
};

class StackList{                //存取list的 top及size
private:
    StackNode *top;      // remember the address of top element,
    int size;            // number of elements in Stack
public:
    StackList(): top(0), size(0){};
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
};
void StackList::Push(int x){

    if(IsEmpty()){
        top = new StackNode(x);
        size = 1;
        return;
    }
        
    StackNode *newNode = new StackNode(x, top);
    top = newNode;
    ++size;
}
void StackList::Pop(){

    if(IsEmpty())
        return;

    StackNode * deletenode = top;   
    top = top->next;
    delete deletenode;
    deletenode = 0;
    --size;
}
bool StackList::IsEmpty(){

    return (size == 0);
}
int StackList::Top(){

    if(IsEmpty())
        return - 1;
    return top->data;
}
int StackList::getSize(){

    return size;
}

int main(){

    StackList s;
    s.Pop();
    s.Push(32);
    s.Push(4);
    std::cout << "top: " << s.Top() << ", size: " << s.getSize() << std::endl;        
    s.Push(15);
    std::cout << "top: " << s.Top() << ", size: " << s.getSize() << std::endl;         
    s.Pop();
    s.Pop();
    std::cout << "top: " << s.Top() << ", size: " << s.getSize() << std::endl;          
    s.Pop();
    std::cout << "top: " << s.Top() << ", size: " << s.getSize() << std::endl;

    return 0;
}