class Solution {

  void insertAtTail(ListNode* &head, ListNode* &tail, int digit)
  {
    ListNode* newNode = new ListNode(digit);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else{
          tail->next = newNode;
          tail = newNode;
     }
  }
  ListNode* add(ListNode* l1 ,ListNode* l2)
  {
    if(l1 == NULL)
    {
        return l2;
    }
    if(l2 == NULL)
    {
        return l1;
    }
    
    int carry = 0;
    ListNode* ansHead = NULL;
    ListNode* ansTail = NULL;

    while(l1 != NULL || l2 != NULL || carry != 0)
    {
        int data1 = 0;
        if(l1 != NULL)
        {
            data1 = l1->val;
            l1 = l1->next;
        }
        int data2 = 0;
        if(l2 != NULL)
        {
            data2 = l2->val;
            l2 = l2->next;
        }
        
        int sum = carry + data1 + data2;
        int lastDigit = sum % 10; 
        
        insertAtTail(ansHead, ansTail, lastDigit);
        
        carry = sum / 10;
    }
    
    return ansHead;
}
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
      // l1 = reverse(l1);
      // l2 = reverse(l2);
      
      ListNode* ans = add(l1,l2);
      
      return ans;
  }
};