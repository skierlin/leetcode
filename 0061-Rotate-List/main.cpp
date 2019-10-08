
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL)
            return NULL;

        int len = get_len(head);
        k = k % len;

        ListNode* end = head;
        for(int i = 0 ; i < k ; i ++)
            end = end->next;

        ListNode* start = head;
        while(end->next != NULL){
            start = start->next;
            end = end->next;
        }

        end->next = head;
        head = start->next;
        start->next = NULL;

        return head;
    }

private:
    int get_len(ListNode* head){
        int res = 0;
        while(head){
            res ++;
            head = head->next;
        }
        return res;
    }
};

