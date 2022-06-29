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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int> m ;
        
        int i= 0;
        while(headA)
        {
            m[headA] = i;
            i++;
            headA = headA->next;
        }
        
        while(headB)
        {
            if(m.find(headB)!=m.end())
            {
                break;
            }
            
            headB = headB->next;
        }
        
        return headB;
    }
};