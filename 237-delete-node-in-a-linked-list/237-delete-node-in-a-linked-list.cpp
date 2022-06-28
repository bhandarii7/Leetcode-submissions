/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode* temp = NULL;
        
        while(node!=NULL)
        {
            temp = node->next;
            
            if(temp->next==NULL)
            {
                node->val = temp->val;
                node->next = NULL;
                break;
            }
            
            node->val = temp->val;
            node = node->next;
            
        }
    }
};