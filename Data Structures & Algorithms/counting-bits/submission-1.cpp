class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        for (int bit = 1; bit <= n; bit++) {
            for (int i = 0; i < 32; i++) {
                if (bit & (1 << i)) {
                    result[bit]++;
                }
            }
        }

        return result;
    }
};
