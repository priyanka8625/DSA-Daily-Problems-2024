/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        //we will do the changes in place
        Node* vowel = new Node(-1), *conso=new Node(-1), *vowelH = vowel, *consoH=conso;
        Node *temp = head;
        while(temp){
            if(isVowel(temp->data)){
                //add it to the vowel list
                vowel->next = new Node(temp->data);
                vowel = vowel->next;
            }else{
                //add it to the end of conso list
                conso->next = new Node(temp->data);
                conso = conso->next;
            }
            temp = temp->next;
        }
        vowel->next = consoH->next;//attach both the lists
        return vowelH->next;//return head of the whole new list
    }
    bool isVowel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    
};