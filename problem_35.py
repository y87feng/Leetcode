class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        min = 0
        max = len(nums) - 1
        while min < max:
            avg = (min+max) // 2
            if target > nums[avg]:
                min = avg+1
            else:
                max = avg
        return min
