/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:

    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        //we can use the concept of count inversions here, which we do to check the no. of inversions
        //needed to sort an array using merge sort
        //let's first convert the BST into array using inorder traversal 
        //and then apply the merge sort logic on the array to count the no. of inversions
        int count=0;
        vector<int> nodes;
        getNodes(root, nodes);
        
        //apply merge sort
        mergesort(nodes, 0, n-1, count);
        return count;
    }
    void getNodes(Node* root, vector<int>& nodes){
        if(root == NULL)
            return;
        
        getNodes(root->left, nodes);
        nodes.push_back(root->data);
        getNodes(root->right, nodes);
    }
    
    void mergesort(vector<int>& nodes, int start, int end, int& count){
        if(start>=end)
            return;
        
        int mid = start+(end-start)/2;
        //sort left part
        mergesort(nodes, start, mid, count);
        //right part
        mergesort(nodes, mid+1, end, count);
        //merge both the parts
        merge(nodes, start, mid, end, count);
    }
    void merge(vector<int>& nodes, int start, int mid, int end, int& count){
        vector<int> temp(end-start+1, 0);
        int left=start, right=mid+1, index=0;
        while(left<=mid && right<=end){
            if(nodes[left] <= nodes[right]){
                temp[index] = nodes[left];
                left++;
                index++;
            }else{
                count += (mid - left + 1);// this indicates the number of shifts 
                                        //required in original array nodes to place right'th element at it's correct position
                temp[index] = nodes[right];
                index++;
                right++;
            }
        }
        while(left<=mid){
            temp[index] = nodes[left];
            left++;
            index++;
        }
        while(right<=end){
            temp[index] = nodes[right];
            index++;
            right++;
        }
        //copy temp into nodes
        index=0;
        while(start<=end){
            nodes[start] = temp[index];
            index++;
            start++;
        }
    }
};