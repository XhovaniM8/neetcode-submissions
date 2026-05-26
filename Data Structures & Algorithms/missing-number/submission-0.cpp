class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Easiest Solution
        int length = nums.size();
        int result = length;

        for (int i = 0; i < length; i++){
            result += (i - nums[i]);
        }

        return result;
    }
};