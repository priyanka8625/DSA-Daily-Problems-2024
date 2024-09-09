/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int top=0, bottom=m-1, left=0, right=n-1;
        
        while(head){
            //fill top side
            for(int i=left; i<=right && head; i++){
                matrix[top][i] = head->val;
                head = head->next;
            }
            top++;
            //fill right side
            for(int i=top; i<=bottom && head; i++){
                matrix[i][right] = head->val;
                head = head->next;
            }
            right--;
            //fill bottom side only if top<=bottom
            if(top<=bottom){
                for(int i=right; i>=left && head; i--){
                    matrix[bottom][i] = head->val;
                    head = head->next;
                }
                bottom--;
            }
            //fill left side only if there's space left
            if(left<=right){
                for(int i=bottom; i>=top && head; i--){
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }
        }
        return matrix;
    }
};