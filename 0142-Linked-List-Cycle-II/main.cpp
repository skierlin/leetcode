
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head == NULL || head->next == NULL)
            return NULL;

        set<ListNode*> records;
        ListNode* curNode = head;
        while(curNode != NULL){
            if(records.find(curNode) != records.end())
                return curNode;

            records.insert(curNode);
            curNode = curNode->next;
        }

        return NULL;
    }
};

/// LinkedList Test Helper Functions
ListNode* createLinkedList(int arr[], int n){

    if( n == 0 )
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curNode = head;
    for( int i = 1 ; i < n ; i ++ ){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

ListNode* tail(ListNode* head){

    if(head == NULL)
        return NULL;

    ListNode* curNode = head;
    while(curNode->next != NULL)
        curNode = curNode->next;

    return curNode;
}

void deleteLinkedList(ListNode* head){

    ListNode* curNode = head;
    while( curNode != NULL ){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }

    return;
}

