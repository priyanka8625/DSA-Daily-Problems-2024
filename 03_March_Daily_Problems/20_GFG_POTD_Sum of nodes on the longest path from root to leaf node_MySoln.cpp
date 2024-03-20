/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int sum=0, maxsum=-1, height=1, maxheight=1;
        calculate(root, height, maxheight, sum, maxsum);
        return maxsum;
    }
    void calculate(Node *node, int height, int &maxheight, int sum, int &maxsum){
        if(node == NULL){
            if(height>maxheight){
                maxheight = height;
                maxsum = sum;
            }else if(height == maxheight){
                maxsum = max(sum, maxsum);
            }
            return;
        }
        calculate(node->left, height+1, maxheight, sum+node->data, maxsum);
        calculate(node->right, height+1, maxheight, sum+node->data, maxsum);
    } 
};