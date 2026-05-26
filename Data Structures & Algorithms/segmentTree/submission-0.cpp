class SegmentTree {
private:
    int n;
    vector<int> tree;

    // Helper to build the tree in O(n)
    void build(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(nums, 2 * node, start, mid);
        build(nums, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    // Helper for O(log n) point update
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    // Helper for O(log n) range query
    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) return 0; // Out of range
        if (L <= start && end <= R) return tree[node]; // Fully in range

        int mid = start + (end - start) / 2;
        return query(2 * node, start, mid, L, R) + 
               query(2 * node + 1, mid + 1, end, L, R);
    }

public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        // A tree for n elements can have up to 4n nodes
        tree.assign(4 * n, 0);
        if (n > 0) build(nums, 1, 0, n - 1);
    }
    
    void update(int index, int val) {
        update(1, 0, n - 1, index, val);
    }
    
    int query(int L, int R) {
        return query(1, 0, n - 1, L, R);
    }
};