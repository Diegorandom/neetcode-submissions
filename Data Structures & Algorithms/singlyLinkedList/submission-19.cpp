class LinkedList {
private: 
    class Node {
        public:
            int value;
            Node* next;

            Node() {
                this->value = 0;
                this->next = nullptr;
            }
    };

    Node* head;
    Node* tail;
    
public:
    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    int get(int index) {
        int idx = 0;
        Node* curr = head;
        while(curr != nullptr){
            if(idx == index){
                return curr->value;
            }
            idx++;
            curr = curr->next;
        }
        return -1;
    }

    void insertHead(int val) {
        if(head != nullptr){
            Node* newNode = new Node();
            newNode->value = val;
            newNode->next = head;
            head = newNode;
        }else {
            Node* newNode = new Node();
            newNode->value = val;
            newNode->next = head;
            head = newNode;
            tail = newNode;
        }
    }
    
    void insertTail(int val) {
        if(head == nullptr){
            Node* newNode = new Node();
            newNode->value = val;
            newNode->next = nullptr;
            tail = newNode;
            head = newNode;
        }else {;
            Node* newNode = new Node();
            newNode->value = val;
            newNode->next = nullptr;
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool remove(int index) {
        if(head == nullptr){
            return false;
        }

        if(index < 0){
            return false;
        }

        if(index == 0){
            if(head == tail){
                head = nullptr;
                tail = nullptr;
            } else {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            return true;
        }
        
        Node* curr = head;
        for(int i=0; i<index; i++){
            if(curr == nullptr || curr->next == nullptr){
                return false;
            }
            if(i == index-1){
                Node* prev = curr;
                Node* target = prev->next;
                prev->next = target->next;
                if(target == tail){
                    tail = prev;
                }
                delete target;
                return true;
            } else {
                curr = curr->next;
            }
        }
        return false;
    }

    vector<int> getValues() {
        Node* curr = head;
        vector<int> values = {};
        while(curr != nullptr){
            values.push_back(curr->value);
            curr = curr->next;
        }

        return values;
    }
};
