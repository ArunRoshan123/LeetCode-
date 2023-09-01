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
// void reverse(ListNode* &head, ListNode* curr, ListNode* prev)
// {
//     if(curr == NULL)
//     {
//         head = prev;
//         return;
//     }
//     ListNode* forward = curr->next;
//     reverse(head, forward, curr);
//     curr -> next = prev;
    
// }

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL or head->next == NULL)
        {
            return head;
        }
        ListNode* curr = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return curr;
    }
};









