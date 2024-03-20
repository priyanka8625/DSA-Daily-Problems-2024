class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ptr = list1;
        // for a=3 we'll loop 2 times
        for (int i = 0; i < a - 1; ++i)
            ptr = ptr->next;
        
        //for b=4 we'll loop 2 times starting from a'th node
        ListNode* qtr = ptr->next;
        for (int i = 0; i < b - a + 1; ++i)
            qtr = qtr->next;
        
        ptr->next = list2;
        while (list2->next)
            list2 = list2->next;
        list2->next = qtr;
        
        return list1;
    }
};