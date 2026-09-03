class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        std::unordered_map<int, int> seen;

        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];
            if (seen.find(diff) != seen.end()) {
                return {seen[diff], i};
            }
            seen.insert({nums[i], i});
        }
        return {};
    }
};
