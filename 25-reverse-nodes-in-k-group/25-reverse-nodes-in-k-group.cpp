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
    ListNode* reverseKGroup(ListNode* head, int k) {
         
        if(!head || head->next == NULL)
             return head;
        
        ListNode* nhead = NULL;
        ListNode* prevfirst = NULL,*currfirst = NULL;
        ListNode* curr = head,*nex = head,*prev = NULL;
        int count = 0;
        while(curr!=NULL)
        {
            count++;
            curr = curr->next;
        }
        
        curr = head;
        count = count/k;
        while(curr != NULL && count!=0)
        {
            currfirst = curr;
            int i=0;
            while(curr!=NULL && i<k)
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
                // if(curr == NULL)
                //     currfirst->next = NULL;
            }
            prevfirst= currfirst; 
            
            count--;
            
            if(count == 0)
            {
               prevfirst->next = curr; 
            }
        }
        return nhead;
    }
};