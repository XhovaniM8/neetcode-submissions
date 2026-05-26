class HashTable {
private: 
    struct Node {
        int key;
        int value;
        Node(int k, int v) : key(k), value(v) {}
    };

    std::vector<std::list<Node>> table;
    int size;
    int capacity;

    int hash(int key) const {
        return key % capacity;
    }

public:
    HashTable(int capacity) : capacity(capacity), size(0) {
        table.resize(capacity);
    }

    void insert(int key, int value) {
        int index = hash(key);

        for (auto& node : table[index]) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }

        table[index].emplace_back(key, value);
        size++;

        if ((double)size / capacity >= 0.5) {
            resize();
        }
    }

    int get(int key) {
        int index = hash(key);
        for (const auto& node : table[index]) {
            if (node.key == key) return node.value;
        }
        return -1;
    }

    bool remove(int key) {
        int index = hash(key);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); it++) {
            if (it->key == key) {
                chain.erase(it);
                size--;
                return true;
            }
        }
        return false;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    void resize() {
        int oldCapacity = capacity;
        capacity *= 2;
        std::vector<std::list<Node>> newTable(capacity);

        for (int i = 0; i < oldCapacity; i++) {
            for (const auto& node : table[i]) {
                int newIndex = node.key % capacity;
                newTable[newIndex].push_back(node);
            }
        }
        table = std::move(newTable);
    }
};
