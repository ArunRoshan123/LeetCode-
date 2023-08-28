class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* A = list1;
        ListNode* B = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* D = dummy;
        
        while(A != NULL and B!= NULL)
        {
            if(A->val <= B->val)
            {
                D->next = A;
                A = A->next;
            }
            else{
                D->next = B;
                B = B->next;
            }
            D = D->next;
        }
        if(A == NULL)
        {
            D->next = B;
        }
        else
        {
            D->next = A;
        }
       return dummy->next;
    }
};