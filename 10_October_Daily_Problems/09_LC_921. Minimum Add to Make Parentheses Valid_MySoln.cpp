class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int invalidClose = 0;
        for(char ch : s){
            if(ch == '('){
                st.push(ch);
            }else if(ch==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }else{
                    invalidClose++;
                }
            }
        }
        return st.size() + invalidClose;
    }
};