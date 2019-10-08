
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head == NULL)
            return false;

        // Use long long type for 64-bit os
        unordered_set<long long> node_address;

        ListNode* p = head;
        while(p != NULL){
            if(node_address.find((long long)(p)) == node_address.end())
                node_address.insert((long long)(p));
            else
                return true;

            p = p->next;
        }

        return false;
    }
};

