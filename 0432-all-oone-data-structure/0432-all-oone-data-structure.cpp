struct Node{
    int cnt;
    Node* prev;
    Node* next;
    unordered_set<string>st;
    Node(int num) : cnt(num),prev(nullptr),next(nullptr){};
};

class AllOne {

private:
    void addNode(Node* pre,int cnt){
        Node* newNode = new Node(cnt);
        newNode->next = pre->next;
        newNode->prev = pre;
        if(newNode->next)
            newNode->next->prev = newNode;
        pre->next = newNode;
        if(pre == lst)
            lst = newNode;
    }
    void removeNode(Node* node){
        Node* preNode = node->prev;
        Node* nextNode = node->next;

        preNode->next = nextNode;
        if(nextNode)
            nextNode->prev = preNode;
        if(lst == node)
            lst = preNode;
        
        delete node;
    }
public:
    unordered_map<string,Node*>mp;
    Node* head;
    Node* lst;

    AllOne() {
        head = new Node(0);
        lst = head;
    }
    
    void inc(string key) {
        if(mp.find(key) == mp.end()){
            if( !head->next || head->next->cnt !=1)
                addNode(head,1);
            head->next->st.insert(key);
            mp[key] = head->next;
        }
        else {
            auto curNode = mp[key];
            int curCnt = curNode->cnt;
            // we need to create node or not
            if(!curNode->next || curNode->next->cnt != curCnt+1)
                addNode(curNode,curCnt+1);
            curNode->next->st.insert(key);
            mp[key] = curNode->next;

            //don't forget 
            curNode->st.erase(key);
            if(curNode->st.empty())
                removeNode(curNode);
        }
    }
    
    void dec(string key) {
        auto curNode = mp[key];
        int curCnt = curNode->cnt;
        if(curCnt == 1)
            mp.erase(key);
        else {
            if(curNode->prev->cnt != curCnt-1)
                addNode(curNode->prev,curCnt-1);
            curNode->prev->st.insert(key);
            mp[key] = curNode->prev;
        }
      curNode->st.erase(key);
       if(curNode->st.empty())
            removeNode(curNode);
        
    }
    
    string getMaxKey() {
        return ( (head == lst) ? "" : *lst->st.begin());
    }
    
    string getMinKey() {
        return !head->next ? "" : *head->next->st.begin();

    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */