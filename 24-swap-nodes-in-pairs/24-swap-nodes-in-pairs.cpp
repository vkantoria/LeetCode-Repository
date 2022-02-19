class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || head->next == NULL)
             return head;
        
        ListNode* nhead = NULL;
        ListNode* prevfirst = NULL,*currfirst = NULL;
        ListNode* curr = head,*nex = head,*prev = NULL;
        
        while(curr != NULL)
        {
            currfirst = curr;
            int i=0;
            while(curr!=NULL && i<2)
            {
                nex = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nex;
                i++;
            }
            
            if(nhead  == NULL)
                nhead = prev;
            else
            {
                prevfirst->next = prev;
                if(curr ==NULL)
                    currfirst->next = NULL;
            }
            prevfirst = currfirst;
        }
        return nhead;
    }
};