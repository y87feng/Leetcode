class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        uni_p = 0
        
        for inx, num in enumerate(nums):
            if nums[inx] != val:
                nums[inx], nums[uni_p] = nums[uni_p], nums[inx]
                uni_p += 1
        return uni_p
            