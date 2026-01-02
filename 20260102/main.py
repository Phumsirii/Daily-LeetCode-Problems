class Solution(object):
    def repeatedNTimes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        memory = dict()
        for num in nums:
            if not num in memory:
                memory[num] = 0
            memory[num] += 1
            if memory[num] > 1:
                return num