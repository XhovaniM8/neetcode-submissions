class Node {
public:
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;

        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (size == 0) {
            tail = newNode;
        }
        size++;
    }

    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (size == 0) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    bool remove(int index) {
        if (index < 0 || index >= size) return false;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (size == 1) tail = nullptr;
        } else {
            Node* curr = head;
            for (int i = 0; i < index - 1; i++) {
                curr = curr->next;
            }
            Node* nodeToRemove = curr->next;
            curr->next = nodeToRemove->next;
            if (index == size - 1) {
                tail = curr;
            }
            delete nodeToRemove;
        }
        size--;
        return true;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* curr = head;
        while (curr) {
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
    }
};