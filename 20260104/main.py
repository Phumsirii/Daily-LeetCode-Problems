class Solution(object):
    
    def countDivisors(self, n):
        divisors = []
        for i in range(1, int(n**0.5) + 1):
            if n % i == 0:
                divisors.append(i)
                if i != n // i:
                    divisors.append(n // i)
        return divisors
    
    def sumFourDivisors(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        for num in nums:
            divisors = self.countDivisors(num)
            if len(divisors) == 4:
                ans += sum(divisors)
        return ans