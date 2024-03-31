class MyQueue {
    stack<int>pushStack,popCumPeekStack;
    void checkpopCumPeekStack(){
        if(popCumPeekStack.empty()){
            while(!pushStack.empty()){
                popCumPeekStack.push(pushStack.top());
                pushStack.pop();
            }
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        pushStack.push(x);
    }
    
    int pop() {
        checkpopCumPeekStack();
        int retItem=popCumPeekStack.top();
        popCumPeekStack.pop();
        return retItem;
    }
    
    int peek() {
        checkpopCumPeekStack();
        return popCumPeekStack.top();
    }
    
    bool empty() {
        return pushStack.empty() && popCumPeekStack.empty();
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