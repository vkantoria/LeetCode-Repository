class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || head->next == NULL)
             return head;
        
        ListNode* curr = head; 
        ListNode* nex = curr->next;
        
       
        
        ListNode* temp = nex->next;
        nex->next =  curr;
        curr->next = swapPairs(temp);
        return nex;
        
    }
};