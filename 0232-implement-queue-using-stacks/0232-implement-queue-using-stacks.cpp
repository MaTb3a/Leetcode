class MyQueue {
    stack<int>st;//1234
public:
    MyQueue() {
    }
    
    void push(int x) {
       if(st.empty()){
           st.push(x);
           return ;
       }
       int tmp = st.top();
       st.pop();
       push(x);
       st.push(tmp);
    }
    
    int pop() {
      int x= st.top();st.pop();
      return x;
    }
    
    int peek() {
       return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */