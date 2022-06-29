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
    bool isPalindrome(ListNode* head) {
        
        if(head->next==NULL)
            return true;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        
        ListNode* head2 = NULL;
        
        while(slow!=NULL)
        {
            nxt = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;
        }
        
        head2 = prev;
        
        while(head<head2)
        {
            if(head->val!=head2->val)
                return false;
            
            head = head->next;
            head2 = head2->next;
        }
        
        return true;
    }
};