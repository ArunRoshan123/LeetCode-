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
    ListNode* getMiddle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = slow->next;
        
        while(fast!= NULL and fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* getReverse(ListNode* head)
    {
        ListNode* prev = NULL;

        while(head!= NULL)
        {
            ListNode* forward = head->next;
            head->next = prev;
            prev = head;
            head = forward;   
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next ==NULL )
        {
            return true;
        }
        
        ListNode* middle = getMiddle(head);
        
        ListNode* reverse = getReverse(middle->next);
        middle->next= reverse;
        
        ListNode* head1 = head;
        ListNode* head2 = middle->next;
        
        while(head2 != NULL)
        {
            if(head1->val != head2->val)
            {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        reverse = getReverse(middle->next);
        middle->next= reverse;
        return true;
    }
};