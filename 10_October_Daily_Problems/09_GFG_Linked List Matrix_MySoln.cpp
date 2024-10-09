class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        // code Here
        Node *head = NULL;
        Node *prevRow = NULL;
        
        for(int i=0; i<mat.size(); i++){
            Node *row = NULL, *tail=NULL;
            for(int j=0; j<mat[0].size(); j++){
                Node *temp = new Node(mat[i][j]);
                if(!row)
                    row = temp;//row head
                if(tail){
                    tail->right = temp;//insert at end
                }
                tail = temp;
                if(prevRow){
                    prevRow->down = temp;//insert at down of prev row
                    prevRow = prevRow->right;
                }
            }
            if(!head){//update head
                head = row;
            }
            prevRow = row;//update prev row
        }
        return head;
    }
};
