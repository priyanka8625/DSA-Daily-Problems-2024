
/*// A Tree node
struct Node
{
	int data;
	struct Node *left, *right;
};*/

class Solution
{
    public:
    
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        int total=1;
        Node* temp=root;
        while(root){
            if(root->data>x && root->data>y){
                root=root->left;
                total++;
            }
            else if(root->data<x && root->data<y){
                root=root->right;
                total++;
            }
            else{
                break;
            }
        }
        total-=k;
        total++;
        root=temp;
        int c=1;
        while(root){
            if(c==total)return root->data;
            if(root->data>x && root->data>y){
                root=root->left;
                c++;
            }
            else if(root->data<x && root->data<y){
                root=root->right;
                c++;
            }
            else{
                break;
            }
        }
    return -1;
    }
};

