class Solution(object):
    def __init__(self):
        self.conversion=list()
    def getValue(self,integer):
        stringInt=str(integer)
        n=len(stringInt)
        resultString=''
        for i in range(len(stringInt)):
            idx=int(stringInt[i])
            resultString+=str(self.conversion[idx])
        return int(resultString)
    def sortJumbled(self, mapping, nums):
        self.conversion=mapping
        return sorted(nums,key=self.getValue)
print('Hello')
mapping = [8,9,4,0,2,1,3,5,7,6]
nums = [991,338,38]
s=Solution()
print(s.sortJumbled(mapping,nums))