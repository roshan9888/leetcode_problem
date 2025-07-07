class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        # xor1=0
        # for i in range(len(nums)):
        #     if nums[i]==val:
        #         nums[i]=float('inf')

        # count=0
        # nums.sort()
        # for i in range(len(nums)):
        #     if nums[i]!=float('inf'):
        #         count+=1


        # return count   

        i=0
        j=len(nums)-1

        while i<j:
            if nums[i]==val and nums[j]==val:
                j-=1
            elif nums[i]==val and nums[j]!=val:
                nums[i],nums[j]=nums[j],nums[i]
                i+=1
                j-=1
            elif nums[i]!=val and nums[j]==val:
                j-=1
                i+=1
            else:
                i+=1

        count=sum(1 for x in nums if x!=val)
        return count   