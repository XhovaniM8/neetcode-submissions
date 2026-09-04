class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    std::unordered_map<int, int> counts;
    for (int x : nums) {
        counts[x]++; // Increments frequency
        if (counts[x] > 1) {
            return true;
        }
    }
    return false;
    }
};