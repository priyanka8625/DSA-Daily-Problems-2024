class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(char ch:s){
            if(!st.empty() && abs(ch - st.top()) == 32)
                st.pop();
            else
                st.push(ch);
        }
        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};