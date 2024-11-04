class MyCircularQueue {
public:
    int top,rear;
    vector<int>v;
    int k2,sz;
    MyCircularQueue(int k) {
        k2 = k;
        top = rear = -1;
        sz = 0;
        v = vector<int>(k);
    }
    
    bool enQueue(int value) {
        if(isFull())return false;
        sz++;
        rear++;
        if(top == -1)top = 0;

        rear%=k2;
        v[rear] = value;
       
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        top++;
        top%=k2;
        sz--;
        return true;
        
    }
    
    int Front() {
        if(isEmpty())return -1;
        return v[top];
    }
    
    int Rear() {
        if(isEmpty())return -1;
        return v[rear];
    }
    
    bool isEmpty() {
        return !sz;
    }
    
    bool isFull() {
        return sz == k2;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */