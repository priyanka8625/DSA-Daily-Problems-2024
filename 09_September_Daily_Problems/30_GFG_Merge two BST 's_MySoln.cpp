class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        int len1=0, len2=0;
        vector<int> nodes;
        len1 = getBSTs(root1, nodes);
        len2 = getBSTs(root2, nodes);
        
        vector<int> merged(len1+len2);
        mergeBSTs(nodes, len1, len2, merged);
        return merged;
    }
    int getBSTs(Node* root, vector<int>& merged){
        if(!root){
            return 0;
        }
        int count = 0;
        count = getBSTs(root->left, merged);
        merged.push_back(root->data);
        count++;
        count += getBSTs(root->right, merged);
        return count;
    }
    void mergeBSTs(vector<int>& nodes, int len1, int len2, vector<int>& merged){
        int left=0, right=len1, index=0, totalLen=len1+len2;
        while(left<len1 && right<totalLen){
            if(nodes[left]<=nodes[right]){
                merged[index++] = nodes[left++];
            }else{
                merged[index++] = nodes[right++];
            }
        }
        while(left<len1){
            merged[index++] = nodes[left++];
        }
        while(right<totalLen){
            merged[index++] = nodes[right++];
        }
    }
};