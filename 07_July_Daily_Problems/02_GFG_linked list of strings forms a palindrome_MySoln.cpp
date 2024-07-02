class Solution {
  public:
    bool compute(Node* head) {
        // Your code goes here
        string str = "";
        while(head){
            str += head->data;
            head = head->next;
        }
        int i=0, j=str.length()-1;
        while(i<j){
            if(str[i]!=str[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
};