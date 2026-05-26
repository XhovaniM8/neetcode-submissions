class Solution {
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        return sort(pairs, 0, pairs.size() - 1);
    }

private:
    vector<Pair> sort(vector<Pair>& pairs, int l, int r) {
        // Base case: a single element is already "sorted"
        if (l >= r) {
            if (l == r) return {pairs[l]};
            return {};
        }

        int mid = l + (r - l) / 2;

        // Recursively split the array
        vector<Pair> left = sort(pairs, l, mid);
        vector<Pair> right = sort(pairs, mid + 1, r);

        // Merge the two sorted halves
        return merge(left, right);
    }

    vector<Pair> merge(vector<Pair>& left, vector<Pair>& right) {
        vector<Pair> result;
        int i = 0, j = 0;

        // Compare elements from both halves and push the smaller one
        while (i < left.size() && j < right.size()) {
            // Use '<=' to maintain stability (prefer left element on equality)
            if (left[i].key <= right[j].key) {
                result.push_back(left[i]);
                i++;
            } else {
                result.push_back(right[j]);
                j++;
            }
        }

        // Exhaust remaining elements in left or right
        while (i < left.size()) result.push_back(left[i++]);
        while (j < right.size()) result.push_back(right[j++]);

        return result;
    }
};