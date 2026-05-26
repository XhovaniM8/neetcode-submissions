#include <vector>

struct Node {
    int key;
    int val;
    Node *left, *right;
    Node(int k, int v) : key(k), val(v), left(nullptr), right(nullptr) {}
};

class TreeMap {
private:
    Node* root;

    // Fixed: Added 'int key' to the parameters so the function can see it
    Node* removeHelper(Node* node, int key) {
        if (!node) return nullptr;

        if (key < node->key) {
            node->left = removeHelper(node->left, key);
        } else if (key > node->key) {
            node->right = removeHelper(node->right, key);
        } else {
            // Found the node to delete
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in right subtree)
            Node* temp = findMinNode(node->right);
            node->key = temp->key;
            node->val = temp->val;
            // Delete the successor
            node->right = removeHelper(node->right, temp->key);
        }
        return node;
    }

    Node* findMinNode(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    void inorder(Node* node, std::vector<int>& keys) {
        if (!node) return;
        inorder(node->left, keys);
        keys.push_back(node->key);
        inorder(node->right, keys);
    }

    Node* insertHelper(Node* node, int key, int val) {
        if (!node) return new Node(key, val);
        if (key < node->key) {
            node->left = insertHelper(node->left, key, val);
        } else if (key > node->key) {
            node->right = insertHelper(node->right, key, val);
        } else {
            node->val = val; // Overwrite existing key
        }
        return node;
    }

public:
    TreeMap() : root(nullptr) {}

    void insert(int key, int val) {
        root = insertHelper(root, key, val);
    }

    int get(int key) {
        Node* curr = root; // Fixed typo: rootl -> root
        while (curr) {
            if (key == curr->key) return curr->val;
            curr = (key < curr->key) ? curr->left : curr->right;
        }
        return -1;
    }

    int getMin() {
        Node* minNode = findMinNode(root);
        return minNode ? minNode->val : -1;
    }

    int getMax() {
        Node* curr = root;
        if (!curr) return -1;
        while (curr->right) curr = curr->right;
        return curr->val;
    }

    void remove(int key) {
        root = removeHelper(root, key);
    }

    std::vector<int> getInorderKeys() {
        std::vector<int> keys;
        inorder(root, keys);
        return keys;
    }
};