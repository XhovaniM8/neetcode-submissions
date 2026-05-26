class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int largestArea = 0;
        
        while (left < right) {
            int minHeight = min(height[left], height[right]);
            int base = right - left;
            largestArea = max(largestArea, base * minHeight);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return largestArea;
    }
};
