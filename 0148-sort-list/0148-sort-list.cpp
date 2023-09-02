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
//     ListNode* findMiddle(ListNode* &head)
//     {
//         ListNode* slow = head;
//         ListNode* fast = head->next;
        
//         while(fast != NULL && fast->next != NULL)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow;
//     }
//     ListNode* mergeList(ListNode* l1 , ListNode* l2)
//     {
//         if(l1 == NULL)
//         {
//             return l2;
//         }
//         if(l2 == NULL)
//         {
//             return l1;
//         }
        
//         ListNode* newNode = new ListNode(-1);
//         ListNode* D = newNode;
        
//         while(l1 != NULL and l2 != NULL)
//         {
//             if(l1->val < l2->val)
//             {
//                 D->next= l1;
//                 D = l1;
//                 l1 = l1->next;
//             }
//             else{
//                 D->next = l2;
//                 D = l2;
//                 l2 = l2->next; 
//             }
//         }
//         if(l1 != NULL)
//         {
//             D->next= l1;
//             l1 = l1->next;   
//         }
//         if(l2 != NULL)
//         {
//             D->next = l2;
//             l2 = l2->next;
//         }
        
//         newNode = newNode->next;
//         return newNode;
        
//     }
//             if(head == NULL || head->next == NULL)
//         {
//             return head;
//         }
        
//         ListNode* mid = findMiddle(head);
        
//         ListNode* list1 = head;
//         ListNode* list2 = mid->next;
//         mid->next = NULL;
        
//         list1 = sortList(list1);
//         list2 = sortList(list2);    
        
//         ListNode* ans = mergeList(list1,list2);
        
//         return ans;
ListNode* mergeList(ListNode* list1, ListNode* list2)
{
    ListNode* dummy = new ListNode(0);
    ListNode* d = dummy;
    
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->val <= list2->val)
        {
            d->next = list1;
            list1 = list1->next;
        }
        else{
            d->next = list2;
            list2 = list2->next;
        }
        d = d->next;
    }
    if(list1 != NULL)
    {
        d->next = list1;
        list1 = list1->next;
    }
    if(list2 != NULL)
    {
        d->next = list2;
        list2 = list2->next;
    }
    return dummy->next;
}    
ListNode* sortList(ListNode* head) {
    
    if(head == NULL or head->next == NULL)
    {
        return head;
    }
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* list1 = head;
    ListNode* list2 = slow->next;
    slow->next = NULL;
    
    list1 = sortList(list1);
    list2 = sortList(list2);
    
    ListNode* ans = mergeList(list1, list2);
    
    return ans;
    }
};