/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        int postIndex=n-1;
        Node* root = buildUtil(in, post, 0, n-1, postIndex);
        return root;
    }
    Node* buildUtil(int in[], int post[], int inStart, int inEnd, int &postIndex){
        if(inStart > inEnd){
            //there're no more elements to add in tree
            return NULL;
        }
        //create a new root node with value of postIndex
        Node* node = new Node(post[postIndex]);
        //decrement postIndex, so that in next call we get the next root node in the right subtree
        postIndex--;
        
        //check if the node is the only element left in the current inorder traversal
        if(inStart == inEnd){
            //we can simply return, as there'll be no left and right child for this node
            return node;
        }
        
        //now get the index of the current root in inorder traversal
        //so that we can identify the left and right children of the root node in inorder
        //and make recursive calls accordingly
        int inIndex = search(in, inStart, inEnd, node->data);
        
        //first apply the recursion for right part of inorder, because the postIndex will be pointing to 
        //next root of the right subtree
        node->right = buildUtil(in, post, inIndex+1, inEnd, postIndex);
        node->left = buildUtil(in, post, inStart, inIndex-1, postIndex);
        
        return node;
    }
    int search(int in[], int start, int end, int key){
        int i=start;
        for(; i<=end; i++)
            if(in[i]==key)
                break;
        return i;
    }
};