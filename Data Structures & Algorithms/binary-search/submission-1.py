class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)
        while left < right:
            mid = left + ((right - left) // 2)
            if nums[mid] > target:
                right = mid
            elif nums[mid] <= target:
                left = mid + 1
        return left - 1 if (left and nums[left - 1] == target) else -1