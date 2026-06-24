// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;

//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    // Implementation of QuickSort
    vector<Pair> quickSort(vector<Pair>& pairs) {
        quickSortHelper(pairs, 0, pairs.size() - 1);
        return pairs;
    }

private:
    void quickSortHelper(vector<Pair>& arr, int s, int e) {
        if (e - s + 1 <= 1) {
            return;
        }

        Pair pivot = arr[e]; // pivot is the last element
        int left = s; // pointer for the left side

        // Partition: elements smaller than pivot on the left side
        for (int i = s; i < e; ++i) {
            if (arr[i].key < pivot.key) {
                swap(arr[left], arr[i]);
                left++;
            }
        }

        // Move pivot in-between left & right sides
        arr[e] = arr[left];
        arr[left] = pivot;

        // Quick sort left side
        quickSortHelper(arr, s, left - 1);

        // Quick sort right side
        quickSortHelper(arr, left + 1, e);
    }
};
