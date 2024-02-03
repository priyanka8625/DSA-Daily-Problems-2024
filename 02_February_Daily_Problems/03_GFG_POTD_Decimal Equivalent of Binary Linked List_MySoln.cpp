/* Below global variable is declared in code for modulo arithmetic
const long long unsigned int MOD = 1000000007; */

/* Link list Node/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

class Solution
{
    public:
        // Should return decimal equivalent modulo 1000000007 of binary linked list 
        long long unsigned int decimalValue(Node *head)
        {
           // Your Code Here
           if(head == NULL)
            return 0;
            
           long long unsigned int ans = 0;
           long long int binDigit=1;//represents the power of 2 starting from 2^0 
           
           //use recursion to convert the node data to decimal values
           convertToDec(head, binDigit, ans);
           
           return ans;
           
        }
        
        void convertToDec(Node* node, long long int& binDigit, long long unsigned int &ans){
            //once we reach the null node
            if(node == NULL){
                return;
            }
            //traverse the whole list and reach the end node
            convertToDec(node->next, binDigit, ans);
            
            //convert current data to decimal 
            ans = (ans + node->data * binDigit)%MOD;
            //update the binDigit value for the previous nodes i.e. 2^1, 2^2, ...
            binDigit = (binDigit*2)%MOD;
        }
};