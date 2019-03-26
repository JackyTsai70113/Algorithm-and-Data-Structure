#include <iostream>

// 不同之處         Struct                     Class
// 型態             值類型                    參考類型
// 記憶體位置       Stack上                    Heap上
// 繼承         只能實現Interface       可繼承也可實現Interface
// NULL           不能NULL                   可為NULL

// *first type*
// class QueueList;

// class QueueNode{
// private:
//     int data;
//     QueueNode *next;
// public:
//     QueueNode():data(0), next(0){};
//     QueueNode(int x):data(x), next(0){};
//     QueueNode(int x, QueueNode *nextnode):data(x), next(nextnode){};
//     friend class QueueList;
// };
// *first type*

// *second type*
struct QueueNode{
    int data;
    QueueNode *next;
    QueueNode():data(0), next(0){};
    QueueNode(int x):data(x), next(0){};
    QueueNode(int x, QueueNode *nextnode):data(x), next(nextnode){};
};
// *second type*

class QueueList{
private:
    QueueNode *front;
    QueueNode *back;
    int size;
public:
    QueueList():front(0), back(0), size(0){};
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int getFront();
    int getBack();
    int getSize();
};
void QueueList::Push(int x){

    if (IsEmpty()){
        front = new QueueNode(x);
        back = front;
        size = 1;
        return;
    }

    back->next = new QueueNode(x);
    back = back->next;
    ++size;
}
void QueueList::Pop(){

    if (IsEmpty()){
        std::cout << "Queue is empty.\n";
        return;
    }

    QueueNode *deletenode = front;
    front = front->next;
    delete deletenode;
    deletenode = 0;
    --size;
}
bool QueueList::IsEmpty(){

    return (size == 0);
}
int QueueList::getFront(){
    return front->data;
}
int QueueList::getBack(){
    return back->data;
}
int QueueList::getSize(){
    return size;
}

int main(){

    QueueList q;
    if (q.IsEmpty()) {
        std::cout << "Queue is empty.\n";
    }
    q.Push(24);
    std::cout<< "After push 24: ";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Push(8);
    std::cout<< "After push 8: ";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Push(23);
    std::cout<< "After push 23: ";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Push(13);
    std::cout<< "After push 13: ";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    std::cout<< "After pop the front element: ";
    std::cout << "front: " << q.getFront() << "     back: " << q.getBack() << "\n";
    q.Push(35);
    std::cout<< "After push 35: ";
    std::cout << "front: " << q.getFront() << "     back: " << q.getBack() << "\n";
    q.Pop();
    std::cout<< "After pop the front element: ";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    std::cout<< "After pop the front element: ";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    std::cout<< "After pop the front element: ";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    std::cout<< "After pop the front element: \n";
    q.Pop();

    return 0;
}