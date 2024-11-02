class Solution(object):
    def isCircularSentence(self, sentence):
        """
        :type sentence: str
        :rtype: bool
        """
        sentence_arr = sentence.split()
        for i in range(len(sentence_arr)-1):
            if sentence_arr[i][-1] != sentence_arr[i+1][0]:
                return False
        return sentence_arr[-1][-1] == sentence_arr[0][0]
    
print(Solution().isCircularSentence("leetcode exercises sound delightful"))