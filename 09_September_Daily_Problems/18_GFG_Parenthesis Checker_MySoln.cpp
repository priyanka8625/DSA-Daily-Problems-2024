class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> parentheses;
        for(char ch : x){
            if(ch == '{' || ch=='[' || ch=='('){
                parentheses.push(ch);
            }else if(parentheses.empty() || (ch=='}' && parentheses.top()!='{') || (ch==']' && parentheses.top()!='[') || (ch==')' && parentheses.top()!='(')){
                return false;
            }else {
                parentheses.pop();
            }
        }
        return parentheses.empty();
    }

};