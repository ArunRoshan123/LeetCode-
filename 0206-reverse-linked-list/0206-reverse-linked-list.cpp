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
void reverse(ListNode* &head, ListNode* curr, ListNode* prev)
{
    if(curr == NULL)
    {
        head = prev;
        return;
    }
    ListNode* forward = curr->next;
    reverse(head, forward, curr);
    curr -> next = prev;
    
}
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        reverse(head,curr,prev);
        
//         if(head == NULL || head->next == NULL)
//         {
//             return head;
//         }
        
//         ListNode* curr = head;
//         ListNode* prev = NULL;
        
//         while(curr != NULL)
//         {
//             ListNode* forward = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = forward;
//         }
        return head;   
    }
};