class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        if (n <= 2) return 2;

        int oneStepBefore = 2;
        int twoStepsBefore = 1;
        int current = 0;

        for (int i = 3; i <= n; i++) {
            current = oneStepBefore + twoStepsBefore;
            twoStepsBefore = oneStepBefore;
            oneStepBefore = current;
        }
        return current;
    }
};
