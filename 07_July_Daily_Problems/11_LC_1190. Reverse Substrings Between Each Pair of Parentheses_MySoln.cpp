class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;//to store start indices of strings starting after a ( bracket
        int n = s.length();
        string ans="";
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(i+1);
            }else if(s[i]==')'){
                int start = st.top();
                st.pop();
                reverse(s.begin()+start, s.begin()+i);
            }
        }
        for(int i=0; i<n; i++){
            if(s[i]!='(' && s[i]!=')')
                ans.push_back(s[i]);
        }
        return ans;
    }
};