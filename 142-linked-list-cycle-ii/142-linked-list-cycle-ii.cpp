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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,int>m;
        
        ListNode* loop = head;
        
        while(loop)
        {
            if(m.find(loop)!=m.end())
            {
                break;
            }
            m[loop] = 1;
            
            loop = loop->next;
        }
        
        return loop;
    }
};