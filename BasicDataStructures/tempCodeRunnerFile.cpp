
    int data;
    QueueNode *next;
    QueueNode():data(0), next(0){};
    QueueNode(int x):data(x), next(0){};
    QueueNode(int x, QueueNode *nextnode):data(x), next(nextnode){};
};