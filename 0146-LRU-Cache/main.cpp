class LRUCache {

private:
    class Node{

    public:
        int key, value;
        Node *prev, *next;

        Node(int k, int v): key(k), value(v), prev(NULL), next(NULL){}
    };

    int capacity;
    unordered_map<int, Node*> data;

    Node* dummyHead;
    Node* tail;

public:
    LRUCache(int capacity): capacity(capacity){
        dummyHead = new Node(-1, -1);
        tail = new Node(-1, -1);

        dummyHead->next = tail;
        tail->prev = dummyHead;
    }

    ~LRUCache(){
        // TODO memory
    }

    int get(int key) {
//        cout << "get " << key << endl;
        if(data.count(key)){
            moveToHead(data[key]);
            assert(dummyHead->next);
//            debug();
            return dummyHead->next->value;
        }
        return -1;
    }

    void put(int key, int value) {
//        cout << "put " << key << " " << value << endl;
        if(data.count(key)){
            data[key]->value = value;
            moveToHead(data[key]);
            return;
        }

        data[key] = new Node(key, value);
        addFirst(data[key]);
//        debug();
        if(data.size() > capacity){
            assert(data.size() == capacity + 1);
            int delKey = removeLast();
            assert(data.count(delKey));
            data.erase(delKey);
//            debug();
        }
    }

private:
    void moveToHead(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->prev = node->next = NULL;
        addFirst(node);
    }

    void addFirst(Node* node){

        node->next = dummyHead->next;
        node->next->prev= node;

        node->prev = dummyHead;
        dummyHead->next = node;
    }

    int removeLast(){

        assert(tail->prev != dummyHead);
        Node* delNode = tail->prev;

        tail->prev = tail->prev->prev;
        tail->prev->next = tail;

        // TODO: delete delNode
        return delNode->key;
    }

    void debug(){

        cout << "Hash Map : sz = " << data.size() << endl;
        for(const pair<int, Node*>& p: data)
            cout << p.first << " : ( " << p.second->key << " , " << p.second->value << " )" << endl;

        cout << "Double Linked List : " << endl;
        Node* cur = dummyHead;
        while(cur)
            cout << "(" << cur->key << "," << cur->value << ") -> ", cur = cur->next;
        cout << "NULL" << endl << endl;
    }
};


