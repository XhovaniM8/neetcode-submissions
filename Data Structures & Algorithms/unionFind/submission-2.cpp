#include <vector>
#include <numeric> // Required for std::iota

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;
    int numComponents;

public:
    UnionFind(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 1);
        numComponents = n;
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool isSameComponent(int x, int y) {
        return find(x) == find(y);
    }

    // Renamed from 'unite' to '_union' to match the test driver
    bool _union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            numComponents--;
            return true;
        }
        return false;
    }

    int getNumComponents() {
        return numComponents;
    }
};