class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx; // value -> index
        idx.reserve(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            int need = target - nums[i];
            auto it = idx.find(need);
            if (it != idx.end()) {
                return {it->second, i};
            }
            idx[nums[i]] = i;
        }
        return {};
    }
};
