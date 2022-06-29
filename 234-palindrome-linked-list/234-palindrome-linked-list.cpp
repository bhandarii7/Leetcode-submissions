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
        
        stack<int>s;
        
        ListNode* ptr = head;
        ListNode* temp = head;
        
        while(ptr)
        {
            s.push(ptr->val);
            ptr = ptr->next;
        }
        
        while(temp)
        {
            int top = s.top();
            s.pop();
            
            if(temp->val!=top)
                return false;
            
            temp = temp->next;
        }
        
        return true;;
        
    }
};