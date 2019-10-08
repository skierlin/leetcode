
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        for(ListNode* pA = headA; pA; pA = pA->next)
            for(ListNode* pB = headB; pB; pB = pB->next)
                if(pA == pB)
                    return pA;
        return NULL;
    }
};


