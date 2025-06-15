class Solution(object):
    def maxDiff(self, num):
        """
        :type num: int
        :rtype: int
        """
        num_str = str(num)
        a = ''
        pointer = 0
        while pointer < len(num_str) and num_str[pointer] == '9':
            a += '9'
            pointer += 1
        for i in range(pointer,len(num_str)):
            if num_str[i] == num_str[pointer]:
                a += '9'
            else:
                a += num_str[i]
        b = ''
        if num_str[0] == '1':
            while pointer < len(num_str) and (num_str[pointer] == '1' or num_str[pointer] == '0'):
                b += num_str[pointer]
                pointer += 1
            for i in range(pointer, len(num_str)):
                if num_str[i] == num_str[pointer]:
                    b += '0'
                else:
                    b += num_str[i]
        else:
            for i in range(len(num_str)):
                if num_str[i] == num_str[0]:
                    b += '1'
                else:
                    b += num_str[i]
        return int(a) - int(b)