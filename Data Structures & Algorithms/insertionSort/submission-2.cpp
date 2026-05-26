// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        int n = pairs.size();
        vector<vector<Pair>> states;

        for (int i = 0; i < n; i++) {
            int j = i - 1;
            Pair current = pairs[i];

            while (j >= 0 && pairs[j].key > current.key) {
                pairs[j + 1] = pairs[j];
                j--; 
            }
            pairs[j + 1] = current;

            states.push_back(pairs);
        }
        return states;
    }
};
