class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) : val(val), next(nullptr), prev(nullptr) {}
};

class Deque {
private:
    Node* head;
    Node* tail;
public:
    Deque() {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void appendleft(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    int pop() {
        if (isEmpty()) return -1;

        int val = tail->val;
        Node* temp = tail; 

        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        return val;
    }

    int popleft() {
        if (isEmpty()) return -1;

        int val = head->val;
        Node* temp = head; 

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        return val;
    }
};
