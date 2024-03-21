//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	int level = 0;
    	//if we obsereve the tree, at level-0 we are traversing from right to left
    	//level-1: left to right, level-2: right to left and so on
    	//hence the pattern is to traverse right-left for even levels 
    	//and left-right for odd levels
    	queue<Node*> q;
    	vector<int> ans;
    	q.push(root);
    	while(!q.empty()){
    	    //first take the size of current level 
    	    int size = q.size();
    	    
    	    //extract all the elements 
    	    vector<int> temp;
    	    for(int i=0; i<size; i++){
    	        Node* ele = q.front();
    	        q.pop();
    	        temp.push_back(ele->data);
    	        if(ele->left) q.push(ele->left);
    	        if(ele->right) q.push(ele->right);
    	    }
    	    //check if the level is odd, then reverse the current traversal of the level
    	    //for evel level, we'll do nothing
    	    if(level&1){
    	        //reverse temp
    	        reverse(temp.begin(), temp.end());
    	    }
    	    level++;
    	    //now insret temp at the end of ans
    	    for(int i=0; i<size; i++){
    	        ans.push_back(temp[i]);
    	    }
    	}
    	return ans;
    }
};