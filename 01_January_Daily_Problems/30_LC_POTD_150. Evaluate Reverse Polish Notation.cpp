class Solution {
    stack<int> operands;
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        int i=0; // to point to each token 
        int op1, op2; // to store two operands

        // iterate over given tokens
        while(i<n){
            // check if the current token is an operand or it's an operator
            if(tokens[i].size()==1 && tokens[i][0]<48){
                //operators have ascii values < 0 i.e <48
                //pop two elements from stack and perform the operation
                op2 = operands.top();
                operands.pop();
                op1 = operands.top();
                operands.pop();
                switch(tokens[i][0]){
                    case '+': 
                        operands.push(op1 + op2);//push back the result
                        break;
                    case '-':
                        operands.push(op1 - op2);//push back the result
                        break;
                    case '*':
                        operands.push(op1 * op2);//push back the result
                        break;
                    case '/':
                        operands.push(op1 / op2);//push back the result
                        break;
                }
            }else{
                //if tokens[i] is a number (operand)
                //push the number onto stack
                operands.push(stoi(tokens[i]));
            }
            i++;
        }
        //return the final output
        return operands.top();
    }
};