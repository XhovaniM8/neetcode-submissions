class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        int res = 1;
        for (int i = 1; i <= x; i++) {
            if ((long long) i * i > x) {
                return res;
            }
            res = i;
        }
        return res;
    }
};