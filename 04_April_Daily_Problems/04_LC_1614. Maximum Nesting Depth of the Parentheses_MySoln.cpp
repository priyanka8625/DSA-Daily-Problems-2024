class Solution {
public:
    int maxDepth(string s) {
        int maxdepth=INT_MIN, depth=0;
        stack<char> st;
        for(char ch: s){
            if(ch == '('){
                //push it onto stack and increase depth
                st.push(ch);
                depth++;
            }else if(ch == ')'){
                //pop opening bracket from stack, and the condition of no opening brackets in stack before closing won't occurs(refer constraints) as s is a VPS
                st.pop();
                depth--;
            }
            maxdepth = max(maxdepth, depth);
        }
        return maxdepth;
    }
};