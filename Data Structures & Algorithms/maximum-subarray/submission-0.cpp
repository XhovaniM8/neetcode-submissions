class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSubarray = nums[0];
        int maxSubarray = nums[0];

        // Check if nums isn't empty
        if (nums.empty()){
            return 0;
        }

        for (int i = 1; i < nums.size(); i++){
            currentSubarray = max(nums[i], currentSubarray + nums[i]);
            maxSubarray = max(maxSubarray, currentSubarray);
        }
        return maxSubarray;
    }
};