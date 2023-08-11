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
/*int getLength(ListNode* head){
    ListNode* temp= head;
    int len=0;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
} 
ListNode* deleteNode(ListNode* head, int position)
{
    
        ListNode* prev = NULL;
        ListNode* curr = head;

        int count = 1 ;
        while(count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;  
    
    return head;
}
*/
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if(head->next == NULL)
            return NULL;
        ListNode* slow= head;
        ListNode* fast= head->next;
        ListNode*prev = NULL;
        
        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                fast = fast->next;
            }
            prev = slow;
            slow = slow->next;
         }
        prev->next = slow->next;
        return head;
    }
};