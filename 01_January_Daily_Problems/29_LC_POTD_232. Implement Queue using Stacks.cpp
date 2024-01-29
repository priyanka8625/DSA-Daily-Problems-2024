class MyQueue {
    stack<int> helpingStack;
    stack<int> actualStack;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        //whenever enqueue operation is called we'll copy the contents of actualStack into helping stack unless actual becomes empty, then push the new element into now-empty actual stack and then push the elements of helpingStack back onto actualStack so that the relative FIFO insertion order is maintained
        while(!actualStack.empty()){
            helpingStack.push(actualStack.top());
            actualStack.pop();
        }
        actualStack.push(x);
        while(!helpingStack.empty()){
            actualStack.push(helpingStack.top());
            helpingStack.pop();
        }
    }
    
    int pop() {
        //to pop an element from the queue simply pop the top of actualStack
        int x = actualStack.top();
        actualStack.pop();
        return x;
    }
    
    int peek() {
        //peek will be the top of actualStack
        return actualStack.top();
    }
    
    bool empty() {
        return actualStack.empty();
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