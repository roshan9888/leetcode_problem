class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        xor1=0
        for i in range(len(nums)):
            if nums[i]==val:
                nums[i]=float('inf')

        count=0
        nums.sort()
        for i in range(len(nums)):
            if nums[i]!=float('inf'):
                count+=1


        return count   