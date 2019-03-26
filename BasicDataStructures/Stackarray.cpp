#include <iostream>
using std::cout;
using std::endl;

class StackArray{
private:
    int top;
    int capacity;
    int *stack;
    void DoubleCapacity();
public:
    StackArray():top(-1), capacity(1){
        stack = new int[capacity];
    }
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
};
void StackArray::DoubleCapacity(){

    capacity *= 2;
    int *newstack = new int[capacity];

    for(int i = 0; i < capacity/2; i++){
        newstack[i] = stack[i];
    }
    delete [] stack;
    stack = newstack;
}
void StackArray::Push(int x){

     if(top == capacity - 1){
        DoubleCapacity();
    }

    stack[++top] = x;
}
void StackArray::Pop(){

    if(IsEmpty())
        return;
    --top;
}
bool StackArray::IsEmpty(){
    
    return (top == -1);
}
int StackArray::Top(){

    if(IsEmpty())
        return -1;
    return stack[top];
}
int StackArray::getSize(){
    return top + 1;
}

int main(){

    StackArray s;
    s.Pop();
    s.Push(14);
    s.Push(9);
    std::cout << "top: " << s.Top() << ", size: " << s.getSize() << std::endl;
    s.Push(7);
    std::cout << "top: " << s.Top() << ", size: " << s.getSize() << std::endl;
    s.Pop();
    s.Pop();
    std::cout << "top: " << s.Top() << ", size: " << s.getSize() << std::endl; 
    s.Pop();
    std::cout << "top: " << s.Top() << ", size: " << s.getSize() << std::endl;

    return 0;
}

