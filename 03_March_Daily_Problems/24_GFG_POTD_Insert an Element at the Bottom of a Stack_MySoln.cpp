class Solution{
public:
    stack<int> insertAtBottom(stack<int> st,int x){
        stack<int> copy;
        while(!st.empty()){
            copy.push(st.top());
            st.pop();
        }
        //insert x at the top of copy
        copy.push(x);
        //now push all the elemnts in copy to st
        while(!copy.empty()){
            st.push(copy.top());
            copy.pop();
        }
        return st;
    }
};