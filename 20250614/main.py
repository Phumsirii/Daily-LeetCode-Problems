class Solution(object):
    def minMaxDifference(self, num):
        """
        :type num: int
        :rtype: int
        """
        num_str = str(num)
        pointer = 0
        while pointer < len(num_str) and num_str[pointer] == '9':
            pointer += 1
        pointer = min(pointer, len(num_str) - 1)
        maxStr = ''
        for i in range(len(num_str)):
            if num_str[i] == num_str[pointer]:
                maxStr += '9'
            else:
                maxStr += num_str[i]
        minStr = ''
        for i in range(len(num_str)):
            if num_str[i] == num_str[0]:
                minStr += '0'
            else:
                minStr += num_str[i]
        return int(maxStr) - int(minStr)
