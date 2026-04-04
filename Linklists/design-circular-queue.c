//Problem 622

typedef struct 
{
    int *arr;
    int front;
    int rear;
    int size;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) 
{
    MyCircularQueue *q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    q->arr = (int*)malloc(k * sizeof(int));
    q->front = q->rear = -1;
    q->size = k;
    return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* q, int value) 
{
    if( (q->rear +1) % q->size == q->front) return false;
    if(q->front == -1) q->front=0;
    q->rear = (q->rear +1) % q->size;
    q->arr[q->rear] = value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* q) 
{
    if(q->front == -1) return false;
    if(q->front == q->rear) 
    {
        q->front = q->rear = -1;
        return true;
    }
    q->front = (q->front+1)%q->size;
    return true;
}

int myCircularQueueFront(MyCircularQueue* q) 
{
    if(q->front == -1) return -1;
    return q->arr[q->front];
}

int myCircularQueueRear(MyCircularQueue* q) 
{
    if(q->front == -1) return -1;
    return q->arr[q->rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* q) 
{
    if(q->front == -1) return true;
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* q) 
{
    if( (q->rear +1) % q->size == q->front) return true;
    return false;
}

void myCircularQueueFree(MyCircularQueue* q) 
{
    free(q->arr);
    free(q);
}