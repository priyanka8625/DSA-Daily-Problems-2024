class CustomStack {
public:
    int top=-1, size=0;
    int *stack;
    CustomStack(int maxSize) {
        stack = new int[maxSize];
        size = maxSize;
    }
    
    void push(int x) {
        if(top == size-1)
            return;
        stack[++top] = x;
    }
    
    int pop() {
        if(top == -1)
            return -1;
        return stack[top--];
    }
    
    void increment(int k, int val) {
        int bottom = 0;
        while(bottom < k && bottom <= top){
            stack[bottom] += val;
            bottom++;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */