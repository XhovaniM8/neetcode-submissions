class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        // To make duplicate-handling easier, sort first.
        sort(nums.begin(), nums.end());

        const int n = (int)nums.size();

        for (int i = 0; i < n; ++i) {
            // Skip duplicate first elements to avoid repeated triplets.
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; ++j) {
                // Optional: skip duplicate second elements for the same i.
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                for (int k = j + 1; k < n; ++k) {
                    // Optional: skip duplicate third elements for the same (i, j).
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;

                    long long sum = 0LL + nums[i] + nums[j] + nums[k];
                    if (sum == 0) {
                        // Triplet is already non-decreasing because array is sorted.
                        // No need to sort the triplet itself.
                        res.push_back({nums[i], nums[j], nums[k]});

                        // TODO (optional but recommended): move k to the next distinct value
                        // while (k + 1 < n && nums[k + 1] == nums[k]) ++k;
                    }
                }
            }
        }

        // TODO (if you didn't skip duplicates inside loops): deduplicate res.
        // You can do:
        // sort(res.begin(), res.end());
        // res.erase(unique(res.begin(), res.end()), res.end());

        return res;
    }
};
